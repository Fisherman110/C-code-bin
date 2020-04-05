#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int Random(int p,int q);

int main()
{
	int result;
	int low,high;

	srand(time(NULL));
	printf("printf low and high:\n");
	scanf("%d %d",&low,&high);
	
	for(int i=0;i<10;i++)
	{
		result=Random(low,high);//产生100以内的随机数:
		printf("%d result is %d\n",i,result);
	}
	return 0;
}
//包含边界
int Random(int p,int q)
{

	int deep;
	int scope;
	int result;

	scope=q-p+1;

	result=rand()%scope;
	return result;
}


