#include<stdio.h>
#define N 4

void backtrack(int);
int cw,bestw,w[N]={5,8,12,9},c;
int main()
{
	c=20;
	cw=0;
	bestw=0;

	backtrack(0);
	printf("%d\n",bestw);

	return 0;
}

void backtrack(int i)
{
	if(i>3)
	{
		if(cw>bestw)bestw=cw;return;
	}
	if(cw+w[i]<=c)
	{
		cw+=w[i];
		backtrack(i+1);
	//	cw-=w[i];
	}
	else
	{
		backtrack(i+1);
	}
}
