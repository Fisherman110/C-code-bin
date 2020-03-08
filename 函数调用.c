#include<stdio.h>
int sum(int);
int main(){
	int n;
	printf("keyin an integer:\n");
	scanf("%d",&n);
	printf("the sum if %d\n",sum(n));

	return 0;
}
//int和char可以不用提前声明，其他类型必须在调用之前进行声明
int sum(int n){
	int s=0;
	for(int i=1;i<=n;i++)
		s=s+i;
	return s;
}
