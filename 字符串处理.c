#include<stdio.h>
#include<string.h>
int main(){
	//char a[20];
	char b[30];
	char c[30];
	int flag=0;
	int num=0;

	char a[20]="helloworld";
	strcpy(b,a);
	printf("copy a2b,:%s\n",b);
	
	printf("keyin c:\n");
	scanf("%s",&c);
	flag=strcmp(a,c);
	printf("comparing result is：%d",flag);
	num=strlen(c);
	printf("c is composed of %d characters.",num);
	
	return 0;
}
