#include<stdio.h>
long f1(int);
int main(){
	int n;
	long sum;
	printf("key in an integer:\n");
	scanf("%d",&n);
	sum=f1(n);
	printf("%ld",sum);
	return 0;
}

long f1(int n){
	long f;
	if(n<=0) {printf("error input");f=0;}
	else if(n==1) f=1;
	else f=n*f1(n-1);

	return f;
}
