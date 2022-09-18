#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
main()
{
	struct sockaddr_in server;
	int lfd,n;
	char rBuf[100]="",sBuf[100]="";
	lfd=socket(AF_INET,SOCK_DGRAM,0);
	server.sin_family=AF_INET;
	server.sin_port=2001;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	printf("Client ready....");

	while(1)
	{
		n=sizeof server;
		printf("Client:");
		gets(rBuf);
		sendto(lfd,rBuf,sizeof rBuf,0,(struct sockaddr *)&server,n);
		if(strcmp(rBuf,"end")==0)
			break;

		recvfrom(lfd,sBuf,sizeof sBuf,0,(struct sockaddr *)&server,&n);
		printf("Server:%s",sBuf);
		if(strcmp(sBuf,"end")==0)
			break;
	}
	close(lfd);
}

