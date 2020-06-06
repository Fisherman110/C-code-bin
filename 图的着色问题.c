#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define n 5

int a[n]={0};
//int EDGE[n][n];

int EDGE[n][n]={{0,0,0,0,0},
		{0,0,1,1,1},{0,1,0,1,1},{0,1,1,0,1},{0,1,1,1,0}};
int CheckColor(int,int);
void PaintColor(int);
void Print();
int main()
{
	//a[5]={0};
//	EDGE[n][n]={{0,0,0,0,0},
//		{0,0,1,1,1},{0,1,0,1,1},{0,1,1,0,1},{0,1,1,1,0}};
	PaintColor(1);
	return 0;
}


int CheckColor(int c,int co)
{
	for(int i=1;i<n;i++)
	{
		if(EDGE[i][c]!=0&&a[i]!=0)
		{
			if(a[i]==co)
				return 0;
		}
	}
	return 1;
}

void PaintColor(int block)
{
	for(int i=1;i<=4;i++)
	{	
		
		if(CheckColor(block,i))
		{	
			a[block]=i;
			if(block==4)
			{
				Print();
				a[block]=0;
				return;
			}
		
			PaintColor(block+1);	
			//for(int j=0;i<5;j++)
			//	a[j]=0;

		}
		
		
	}
}

void Print()
{
	for(int i=1;i<n;i++)
		printf("%d->%d\n",i,a[i]);
	printf("-----------\n");
}
