#include<stdio.h>
#define N 4
int f1(int);
int a,b;//外部变量，全局变量
int main(){
	a=8;
	b=f1(a);
	printf("%d",b);
	return 0;
}

int f1(int a){
	int s=1;
	for(int i=1;i<N;i++)
		s=s*a;
	return s;
}
