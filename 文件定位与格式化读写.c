#include<stdio.h>
#include<stdlib.h>

struct stu
{
	char name[10];
	int num;
	int age;
	char addr[15];
}boy,*qq;


int main(){
	FILE *fp;
	char ch;
	int i=1;
	qq=&boy;
	if((fp=fopen("./file1","wb+"))==NULL)
	{
		printf("Cannot open file strike any key exit");
		exit(1);
	}
	rewind(fp);
	fseek(fp,i*sizeof(struct stu),0);
	fread(qq,sizeof(struct stu),1,fp);
	printf("\n\nname\tnumber	age	addr\n");
	printf("%d\t%5d %7d	%d\n",qq->name,qq->num,qq->age,qq->addr);
	return 0;
}
