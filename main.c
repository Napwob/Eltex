#include <stdio.h>
#include <math.h>

int main() {
	printf("Enter N: ");
	int N;
	scanf("%d",&N);
	int Array[N][N];
	int count = 1;
	
	int from=0,to=N;
	for(int h=0;h<N/2+1;h++)
	{
		for(int i=from;i<to;i++)
		{
			//printf("%d %d\n",from,i);
			Array[from][i] = count;
			count++;
		}
		//printf("\n");
		
		for(int i=from+1;i<to;i++)
		{
			//printf("%d %d\n",i,to-1);
			Array[i][to-1] = count;
			count++;
		}
		//printf("\n");
		
		for(int i=to-2;i>=from;i--)
		{
			//printf("%d %d\n",to-1,i);
			Array[to-1][i] = count;
			count++;
		}	
		//printf("\n");
		
		for(int i=to-2;i>from;i--)
		{
			//printf("%d %d\n",i,from);
			Array[i][from] = count;
			count++;
		}	
		//printf("\n");
		from++;
		to--;
	}
	for(int k=0;k<N;k++)
	{
		for(int l=0;l<N;l++)
		{
			printf("%4d ",Array[k][l]);
		}
		printf("\n");
	}
	
	return 0;
}
