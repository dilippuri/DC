#include<stdio.h>
#include<stdlib.h>

int main(){
system("procinfo | grep 'CPU' | awk { print $4} > load.txt");
int a;
FILE *fp;
fp = fopen("load.txt","r");
fscanf(fp,"%d",a);
fclose(fp);
if(a > 80)
	printf("CPU is Overloaded");
else if(a > 50 && a < 80)
	printf("CPU is Moderately loaded");
else
	printf("CPU is running fine");
	return 0;
}