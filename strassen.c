#include<stdio.h>
#define N 4
//typedef int(*PTR)[N];


PTR Plus(int (*)[N],int (*)[N]);
PTR Multiple(int (*)[N],int (*)[N]);

int main()
{
	int a[N][N];
	int b[N][N];
	int i,j;
	int (*p)[N];
	int (*q)[N];
	int (*r)[N];


	p=a;
	q=b;
	printf("key in %d numbers:\n",N*N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&a[i][j]);
	}
	//printf("%d",N);
	
	printf("key in %d numbers:\n",N*N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&b[i][j]);
	}
	r=Plus(p,q);
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d ",*(*(r+i)+j));
	}
	

	return 0;
}

PTR Plus(int (*w)[N],int (*e)[N])
{
	int (*m)[N];
	int y[N][N];
	m=y;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			*(*(m+i)+j)=*(*(w+i)+j)+*(*(e+i)+j);
		}
	}
	return m;
}

PTR Multiple(int (*o)[N],int (*p)[N])
{
	int (*g)[N];
	
	return g;
}
