#include<stdio.h>

int main(int argc,char *argv){
	while(argc-->1)
		printf("%s\n",*++argv);
	return 0;
}
