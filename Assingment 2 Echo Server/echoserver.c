#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *s){
	perror(s);
	exit(1);
} 

int main(int argc, char *argv[]){
	
	//declaration part
	int sockfd,newsockfd,portno;//file discriptor
	char buffer[255];//message
	struct sockaddr_in serv_addr,cli_addr;//server and client address
	
	//Checking if PORT is provided
	if(argc < 2){
		fprintf(stderr,"ERROR, No PORT provided\n");
		exit(1);
	}
	
	//socket creation
	       //socket(domain,type,protocol)  
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	//sockfd contains 0 retured by socket() if everything works fine otherwise contains -1
	if(sockfd < 0)
		error("ERROR opening socket");
	
	//clear serv_addr if it contain some garbadge value
	bzero((char *) &serv_addr, sizeof(serv_addr));
	
	//variables of struct sockaddr_in
	serv_addr.sin_family = AF_INET;//sin_family can be AF_INET(internet domain) or AF_UNIX(unix domain)
	portno = atoi(argv[1]);
	serv_addr.sin_port = htons(portno);//contains PORT number, first converted from strings of digits to integer using atoi() than from host byte order to network byte order using htons()
	serv_addr.sin_addr.s_addr = INADDR_ANY;//contains the IPA of machine on which it is running
	
	//bind socket with IPA and PORT number
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR on Binding");
	
	//listen(file discriptor, number of users)
	listen(sockfd,2);
	
	//accept keep blocking the connection until the request is sent by client 
	newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,(socklen_t *)&cli_addr);
	
	if(newsockfd < 0)
		error("ERROR on Accept");
	
	//Clears buffer
	bzero(buffer,256);
	
	//Reads the message send by client
	int n = read(newsockfd,buffer,255);
	
	if(n < 0)
		error("ERROR reading from socket");
	
	printf("Here is the message : %s\n",buffer);
	
	//Send reply to Client
	n = write(newsockfd,"Server : Message Recieved",30);
	
	if(n < 0)
		error("ERROR writing to socket");
	
	//terminate the connection
	close(newsockfd);
	close(sockfd);
	
	return 0;
}