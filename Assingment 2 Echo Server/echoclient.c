#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>  

void error(const char *s){
	perror(s);
	exit(1);
} 

int main(int argc,char *argv[]){
	
	int sockfd,portno;
	char buffer[255];
	struct sockaddr_in serv_addr;
	struct hostent *server;
	
	server = gethostbyname(argv[1]);
	
	if(argc < 3){
		fprintf(stderr,"ERROR, No PORT provided\n");
		exit(1);
	}
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	if(sockfd < 0)
		error("ERROR opening socket");
	
	if(server == NULL)
		error("ERROR No such host");
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,server->h_length);
	portno = atoi(argv[2]);
	serv_addr.sin_port = htons(portno);
	
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");
	
	bzero(buffer,256);
	
	printf("Enter message : ");
	fgets(buffer,255,stdin);
	
	int n = write(sockfd, buffer, strlen(buffer));
	
	if(n < 0)
		error("ERROR writing to socket");
	
	bzero(buffer,256);
	
	n = read(sockfd, buffer, 255);
	
	if(n < 0)
		error("ERROR reading from socket");
	
	printf("%s\n",buffer);
	
	close(sockfd);
	
	return 0;
}