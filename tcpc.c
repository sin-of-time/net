#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	struct sockaddr_in server;
	int lfd;
	char rBuf[100]="",sBuf[100]="";
	lfd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_port=2000;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	//server.sin_addr.s_addr=inet_addr("172.17.3.2");
	printf("\nClient ready....");
	connect(lfd,(struct sockaddr *)&server,sizeof server);
	while(1)
	{
		printf("\nClient:");
		gets(rBuf);
		send(lfd,rBuf,sizeof rBuf,0);
		if(strcmp(rBuf,"end")==0)
			break;

		recv(lfd,sBuf,sizeof sBuf,0);
		printf("\n Server:%s",sBuf);
		if(strcmp(sBuf,"end")==0)
			break;

		printf("\n");
	} 
	close(lfd);
}

