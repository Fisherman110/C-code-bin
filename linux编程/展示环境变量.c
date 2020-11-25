//这个文件用于获取当前运行可执行文件那个shell的环境变量
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
extern char **environ;
int main()
{
	int i;
	for(i=0;environ[i]!=NULL;i++)
		printf("%s\n",environ[i]);
	return 0;
}
