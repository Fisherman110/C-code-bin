#include<stdio.h>
int f1(int);
int main(){
	int a;
	printf("key in an integer:\n");
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
		printf("%d\n",f1(i));
	return 0;
}

int f1(int a){
	static int n=1;
	n=n*a;
	return n;
}
