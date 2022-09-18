#include<stdio.h>
int main()
{
	int B,outR,n,N,i,buff=0,drop;
	printf("Enter the bucket size : ");
	scanf("%d",&B);
	printf("Outgoing packet rate : ");
	scanf("%d",&outR);
	printf("No. of packets : ");
	scanf("%d",&N);
	
	
	for(i=0;i<N;i++){
		printf("\nEnter incoming packet size : ");
		scanf("%d",&n);
		if(buff+n<=B){
			buff+=n;
			drop=0;
		}
		else {
			drop=n-B+buff;
			buff=B;
		}
		printf("Dropped packets\t: %d\nBuffer size\t: %d\nAfter outgoing\t: ",drop,buff);
		if(buff>outR)
			buff-=outR;
		else 
			buff=0;
		printf("%d\n",buff);
	}
	return 0;
}

