#include<stdio.h>

int main(){
	int *p1,*p2;
	int a,b;
	p1=&a;
	p2=&b;

	printf("key in a and b\n");
	//scanf("%d %d",p1,p2);
	scanf("%d %d",&a,&b);
	printf("%d,%d\n",*p1,*p2);
	return 0;
}
