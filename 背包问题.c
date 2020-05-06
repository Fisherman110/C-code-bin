#include<stdio.h>
#define N 9


int package(int,int,int *,int *,int *);
int main()
{
	int w[N]={5,9,0,23,12,8,7,34,5};
	int v[N]={2,9,30,8,4,56,8,10,2};
	int z[N]={0};
	int C=60;
	int j=C;

	int result;
	result=package(60,8,w,v,z);
	printf("%d\n",result);

	return 0;
}

int package(int j,int i,int *w,int *v,int *z)
{
	if(i==-1) return 0;
	if(j>=w[i])
	{
		if(package(j,i-1,w,v,z)>=(v[i]+package(j-w[i],i-1,w,v,z))){
			return package(j,i-1,w,v,z);}
		else{
		z[i]=1;
		return v[i]+package(j-w[i],i-1,w,v,z);
		}

	}
	else{
		return package(j,i-1,w,v,z);
	}
}
