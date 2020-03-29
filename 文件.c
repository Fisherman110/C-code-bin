#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	char ch;
	if((fp=fopen("./读取文件","rt"))==NULL)
	{
		printf("errors in open file 文件读取\n");
		exit(1);
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		if(ch=='\n')
			printf("*");//注意文件读取到末尾最后会读取一个空格，然后是EOF
		printf("%c",ch);
		ch=fgetc(fp);
		
	}
	printf("#");
	fclose(fp);
	return 0;
}
