#include<stdio.h>
#define N 5

void Distance(int *,int (*)[N],int *);
int main()
{
	int d[N][N]={{1000,10,1000,30,100},{1000,1000,50,1000,1000},{1000,1000,1000,1000,10},
		{1000,1000,20,1000,60},{1000,1000,1000,1000,1000}};
	int p[N];
	int dist[N];
	//定义数据,1000表示不存在路径
	
	for(int i=1;i<N;i++)
		p[i]=0;
	p[0]=1;
	//只有源点包含
	Distance(p,d,dist);
	for(int i=1;i<N;i++)
		printf("%d\n",dist[i]);

	return 0;
}

void Distance(int *p,int (*d)[N],int *dist)
{
	for(int i=1;i<N;i++)
			dist[i]=d[0][i];//初始化距离数组；

	int leastdistance;
	int flag;
	for(int i1=1;i1<N;i1++)
	{
		leastdistance=500;
		flag=10;
		//if(i1==(N-1))//选出距离最近的点加入集合
		//{
		//	for(int i=1;i<N;i++)
		//	{
		//		if(p[i]==0)
		//		{
		//			leastdistance=dist[i];
		//			flag=i;
		//			p[i]=1;
		//		}
		//	}
		//}else{
		for(int i=1;i<N;i++)
		{
			if(p[i]==0&&dist[i]<leastdistance)
			{
				leastdistance=dist[i];
				flag=i;
			}
		}
		p[flag]=1;//距离最短的点加入集合
		printf("%d plus\n",flag);
		printf("%d dist[%d]\n",dist[flag],flag);
		
		//}

		//更新距离
		for(int i=1;i<N;i++)
		{
			if(p[i]==0)
			{
				for(int i2=1;i2<N;i2++)
				{
					if(p[i2]==1&&((d[i2][i]+dist[i2])<dist[i]))
						dist[i]=d[i2][i]+dist[i2];
				}
			}
		}

		

	}
}
