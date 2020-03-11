#include<stdio.h>
void f1(int *a,int *b);
int main(){
	int *p1,*p2,a,b;
	printf("key in a and b");
	scanf("%d %d",&a,&b);
	
	p1=&a,p2=&b;
	f1(p1,p2);
	printf("%d>%d",a,b);
	return 0;
}

void f1(int *a,int *b){
	int tmp;
	
	if(*a<*b) {tmp=*a;*a=*b;*b=tmp;}
}
