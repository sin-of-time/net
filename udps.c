#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
main()
{
	struct sockaddr_in client,server;

	int lfd,n;
	char rBuf[100]="",sBuf[100]="";
	lfd=socket(AF_INET,SOCK_DGRAM,0); 

	server.sin_family=AF_INET;
	server.sin_port=2001;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");

	bind(lfd,(struct sockaddr *)&server,sizeof server);
	printf("Server ready,waiting for client....");
	n=sizeof client;
	while(1)
	{
		recvfrom(lfd,rBuf,sizeof rBuf,0,(struct sockaddr *)&client,&n);
		printf("Client:%s",rBuf);
		if(strcmp(rBuf,"end")==0)
			break;

		printf("Server:");
		gets(sBuf);
		sendto(lfd,sBuf,sizeof sBuf,0,(struct sockaddr *)&client,n);
		if(strcmp(sBuf,"end")==0)
			break;
	}
	close(lfd);
}

