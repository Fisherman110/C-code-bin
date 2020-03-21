#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp;
	if((fp=fopen("./file","wt+"))==NULL)
	{
		printf("\nerror on open ./file!");
		//getch();
		exit(1);
	}
	int i,j;
	char ch,x,y;
	for(i=0;i<6;i++)
	{
		printf("keyin 6 char:\n");
		scanf("%c",&ch);
		fputc(ch,fp);
	}
	rewind(fp);
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp);
	}
	printf("\n");
	fclose(fp);
	return 0;

}
