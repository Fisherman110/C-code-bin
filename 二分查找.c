#include<stdio.h>
int binarysearch(int a[],int x,int i,int j);//从数组的i到j位里查找x,返回x的下标

int main()
{
	int a[10],i,j,d,v;
	printf("key in 10 num:\n");
	for(i=0;i<10;i++)
		scanf("%d",a+i);
	i=0,j=9;
	printf("key in an int to search:\n");
	scanf("%d",&v);
	d=binarysearch(a,v,i,j);
	printf("the num is in %d pos\n",d);
	return 0;
}
//数组默认从小到大排列
int binarysearch(int a[],int x,int i,int j)
{
	int m;
	if(i>j)
		return -1;
	else
		m=(i+j)/2;
	//如果出现i>j说明找不到x

	if(a[m]>x)
		{j=m-1;return binarysearch(a,x,i,j);}
	else if(a[m]<x)
	{
		i=m+1;
		return binarysearch(a,x,i,j);
	}
	else if(a[m]==x)
		return m;
}


