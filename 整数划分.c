#include<stdio.h>
int q(int n,int m);

int main()
{
	int t;
	printf("key in an integer:\n");
	scanf("%d",&t);
	printf("%d",q(t,t));
	return 0;
}

int q(int n,int m)
{
	if(n==1||m==1)
		return 1;
	else if(n<m)
		return q(n,n);
	else if(n==m)
		return 1+q(n,n-1);
	else
		return q(n,m-1)+q(n-m,m);
}
