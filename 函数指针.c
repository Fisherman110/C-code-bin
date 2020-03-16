#include<stdio.h>
int max(int ,int);
int main(){
	int (*p)();
	p=max;

	int a,b,c;
	printf("key in two nums:\n");
	scanf("%d %d",&a,&b);
	c=(*p)(a,b);
	printf("the bigger one is: %d\n",c);
	return 0;
}

int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}
