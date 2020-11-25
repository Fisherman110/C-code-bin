//这是用errno.h来获取当前错误代码和错误信息的代码
#include<stdio.h>
#include<errno.h>

int main()
{
	printf("errno1=%d\n",errno);
	if(fopen("any","r")==NULL)
	{
		perror("fopen");
	}
	return 0;
}
