#include<stdio.h>
#define N 4
int a[N][N]={0};
void cover(int,int,int,int);

int main()
{
	int s=N/2;
	a[s][s]=6;
	printf("%d\n",a[1][1]);
	cover(0,N-1,0,N-1);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	//printf("%d",L1);
	return 0;
}

void cover(int r1,int r2,int c1,int c2)
{
	
	if((r2-r1)==0)
		return;
	int i=(r1+r2)/2;
	int j=(c1+c2)/2;
	if(a[i][j]!=0)
	{
		a[i][j+1]=4;
		a[i+1][j]=4;
		a[i+1][j+1]=4;
		cover(r1,i,c1,j);
		cover(r1,i,j+1,c2);
		cover(i+1,r2,c1,j);
		cover(i+1,r2,j+1,c2);
		printf("%d %d \n",i,j);
		return;
	}

	if(a[i][j+1]!=0)
	{
		a[i][j]=1;
		a[i+1][j]=1;
		a[i+1][j+1]=1;
		cover(r1,i,c1,j);
		cover(r1,i,j+1,c2);
		cover(i+1,r2,c1,j);
		cover(i+1,r2,j+1,c2);
		printf("%d %d \n",i,j+1);
		return;
	}

	if(a[i+1][j]!=0)
	{
		a[i][j]=2;
		a[i][j+1]=2;
		a[i+1][j+1]=2;
		cover(r1,i,c1,j);
		cover(r1,i,j+1,c2);
		cover(i+1,r2,c1,j);
		cover(i+1,r2,j+1,c2);
		printf("%d %d \n",i+1,j);
		return;
	}

	if(a[i+1][j+1]!=0)
	{
		a[i][j]=3;
		a[i][j+1]=3;
		a[i+1][j]=3;
		cover(r1,i,c1,j);
		cover(r1,i,j+1,c2);
		cover(i+1,r2,c1,j);
		cover(i+1,r2,j+1,c2);
		printf("%d %d \n",i+1,j+1);
		return;
	}

}
