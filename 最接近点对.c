#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 4
struct point{
	float x;
	float y;
};


float distance(struct point *,int n1);
float min(double d1,double d2);
int main()
{
	float result;
	struct point p1[N];
	for(int i=0;i<N;i++)
	{
		printf("key in %d x and y\n",i);
		scanf("%f %f",&p1[i].x,&p1[i].y);
	}
	result=distance(p1,N);
	printf("result is %f\n",result);
	//printf("helloworld\n");
	return 0;
}



float min(double d1,double d2)
{
	if(d1>=d2)
		return d2;
	else
		return d1;
}

float distance(struct point p[],int n1)
{
	int n=n1;
	if(n=2)
		return sqrt(pow((p[1].x-p[0].x),2)+pow((p[1].y-p[0].y),2));
	else if(n==1)
		return 10000;
	int pa,q;
	float m,sum,d1,d2,d,tempd,tempdd;//求出所有点的x平均值m
	for(int i=0;i<n;i++)
	{
		sum+=p[i].x;
	}

	m=(float)sum/n;
	//printf("%f",m);
	//将点分为两组，大小分别为pa,q,分别放置于ps,py中
	for(int i=0;i<n;i++)
	{
		if(p[i].x<=m)
			pa++;
		else
			q++;
	}

	struct point ps[pa],py[q];
	for(int i=0;i<n;i++)
	{
		if(i<pa)
			ps[i]=p[i];
		else
			py[i-pa]=p[i];
	}

	d1=distance(ps,pa);
	d2=distance(py,q);
	d=min(d1,d2);
	tempd=d;
	tempdd=d;

	//对于ps所有距离m小于d的点,检索py里面距离m小于d且与ps的点纵坐标差不超过2d的点计算距离，
	//如果小于d则会保留在tempdd中，最后判断返回值
	for(int i=0;i<pa;i++)
	{
		if((m-ps[i].x)<=d)
		{
			for(int j=0;i<q;i++)
			{
				if((py[j].x-m)<=d&&fabs(py[j].y-ps[i].y)<=d)
				{
					tempd=sqrt(pow((py[j].x-ps[i].x),2)+pow((py[j].y-ps[i].y),2));
					if(tempd<d)
					{	
						if(tempdd<tempd)
							tempdd=tempd;
					}
				}
			}
		}
	}

	if(tempdd<d)
		return tempdd;
	else
		return d;

}
