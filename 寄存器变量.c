#include<stdio.h>
int f(int);
//寄存器变量只能是局部变量，不能是静态变量，且只能定义有限个
int main(){
	int a;
	printf("key in an integer:\n");
	scanf("%d",&a);
	printf("%d",f(a));
	return 0;
}

int f(int n){
	int s=1;
	register int i;
	for(i=1;i<=n;i++)
		s=s*i;
	return s;
}
