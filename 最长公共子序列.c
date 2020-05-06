#include<stdio.h>
#define n1 9
#define m1 12
char *x,*y;
void LCSLength(int,int,char *,char *,int [n1][m1],int [n1][m1]);
void LCS(int ,int ,char *,int [n1][m1]);

int main()
{
	char a[n1]={'#','R','U','W','C','S','K','X'};
	char b1[m1]={'#','U','B','W','N','C','S','J','D','I','E'};
	int c[n1][m1];
	int b[n1][m1];
	x=a,y=b1;
	
	
	LCSLength(7,10,x,y,c,b);
	LCS(7,10,x,b);
	return 0;
}


void LCSLength(int m,int n,char *x,char *y,int c[n1][m1],int b[n1][m1])
{
	int i,j;
	for(i=0;i<=m;i++) c[i][0]=0;
	for(i=0;i<=n;i++) c[0][i]=0;

	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(x[i]==y[j]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}else{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
		}
}
void LCS(int i,int j,char *x,int b[n1][m1])
{
	if(i==0||j==0)return;
	if(b[i][j]==1){
		LCS(i-1,j-1,x,b);
		printf("%c\n",x[i]);
	}
	else if(b[i][j]==2) LCS(i-1,j,x,b);
	else LCS(i,j-1,x,b);

}
