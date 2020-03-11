#include<stdio.h>
#define N 10
int f1(int a[N]);
int main(){
	int a[N],i,j;
	printf("key in %d integers\n",N);
	for(i=0;i<N;i++){scanf("%d",&a[i]);}
	//printf("1");
	j=f1(a);
	printf("%d",j);
	return 0;
}

int f1(int a[N]){
	int sum;
	for(int i=0;i<N;i++)
		sum=sum+a[i];
	return sum;
}

