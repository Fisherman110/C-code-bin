#include<stdio.h>
int max(int,int);
int main(){
	extern int A,B;
	printf("%d\n",max(A,B));
	return 0;
}
int A=20,B=-29;
int max(int a,int b){
	int z;
	z=a>b?a:b;
	return z;
}
