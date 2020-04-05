#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 6

int Random(int p,int q);
int Partition(int a[],int p,int r);
int RandomizedPartition(int a[],int p,int r);

int main()
{
	int result;
	int a[N];
	int low,high;

	srand(time(NULL));
	
	printf("key in %d nums:\n",N);
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
	result=RandomizedPartition(a,0,N-1);



	printf("result is: %d\n",result);
	
	for(int i=0;i<N;i++)
		printf("%d ",a[i]);

	return 0;
}
//包含边界
int Random(int p,int q)
{

	int deep;
	int scope;
	int result;

	scope=q-p+1;

	result=rand()%scope;
	return result;
}

int Partition(int a[],int p,int r)
{
	int x=a[p];
	int i=p;
	int j=r+1;

	while(2>1)
	{
		while(a[++i]<x);
		while(a[--j]>x);
		if(i>=j) break;
		int temp;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}

	printf("%d %d",a[p],a[j]);
	a[p]=a[j];
	a[j]=x;
	printf("%d %d",a[p],a[j]);
	return j;
}

int RandomizedPartition(int a[],int p,int r)
{
	int i=Random(p,r);
	int temp;
	temp=a[i];
	a[i]=a[p];
	a[p]=temp;
	return Partition(a,p,r);
}


