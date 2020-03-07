#include<stdio.h>
int main(){
	int a[10];
	int i,j;
	printf("keyin 10 integers:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(j=0;j<10;j++)
		printf("a[%d] is %d\n",j,a[j]);
	return 0;
}
