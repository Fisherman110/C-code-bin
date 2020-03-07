#include<stdio.h>
int main(){
	int a[3][4]={{1,2,3,4},{23,56,8,42},{8,0,23,43}};
	//C语言按行存储多维数组，先存贮a[0][0],a[0][1]...
	
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++)
			printf("a[%d][%d] is: %d   ",i,j,a[i][j]);
		printf("\n");
	}
	return 0;
}
