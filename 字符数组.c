#include<stdio.h>
#include<string.h>
int main(){
	char a[]="this is a char array";
	printf("%s\n",a);

	char b[11];
	printf("key in a string, no more than 10 characters, no sapce:");
	scanf("%s",b);
	printf("%s",b);

	//char c[20];
	//printf("key in a sentence, space is ok:");
	//gets(c);
	//puts(c);
	return 0;
}
