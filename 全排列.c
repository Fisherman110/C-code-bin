#include<stdio.h>

void Perm1(int a[],int k,int m)
{
	int temp;
	if(k==m)
	{for(int i=0;i<=m;i++)
		printf("%d",a[i]);
		printf(" ");
	}
	else
	{
		for(int i=k;i<=m;i++)
		{
			//Swap(a[k],a[i]);
			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
			Perm1(a,k+1,m);
			//Swap(a[k],a[i]);
			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
		}
	}
}

int main()
{	
	int a[5];
	printf("key in 5 integers:\n");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	Perm1(a,0,4);

	return 0;
}

