#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	int result;
	srand(time(NULL));

	for(int i=0;i<10;i++)
	{
		result=rand()%100;//产生100以内的随机数:
		printf("%d result is %d\n",i,result);
	}
	return 0;
}
