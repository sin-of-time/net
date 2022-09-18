//LINK STATE ROUTING

#include<stdio.h>
void main(){
	int i,j,k,n,cost_matrix[100][100],val,min,hop[100],source;
	char node[20];
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	min=1000;

	/*
	for(i=0;i<n;i++){

	printf("enter  node %d name",i);
	scanf("%c",&node[i]);


	} */
	for(i=0;i<n;i++){
		hop[i]=-1;
		for(j=0;j<n;j++){
			printf("Enter the distance from node %d -> %d : ",i+1,j+1);

			scanf("%d",&cost_matrix[i][j]);

		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){

			if(cost_matrix[i][j]==-1){
				for(k=0;k<n;k++){
					if(cost_matrix[k][j]>0){

						val=cost_matrix[i][k]+cost_matrix[k][j];
					}
					if(min>val){
						min=val;
						hop[i]=k;



					}


				}
				cost_matrix[i][j]=min;

			}
		}


	}

	for(i=0;i<n;i++){
		printf("Enter the source node : ");
		scanf("%d",&source);
		printf("The distance is \n");
		for(i=0;i<n;i++){
			printf("%d -> %d : %d\n",source,i+1,cost_matrix[source-1][i]);

		}
	}
	printf("hop node is %d\n",hop[source]);



}

