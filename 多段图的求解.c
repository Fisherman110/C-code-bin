#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MaxState 100

int minRoad[MaxState][MaxState];
void multiStageGraph(int stageNum, int *numPerStage);

int main()
{
    int i, k, ni[MaxState];
    while(scanf("%d", &k),k != -1)
    {
        for(i = 0; i < k; ++i)
        {
            scanf("%d", &ni[i]);
        }
        multiStageGraph(k, ni);
    }
    return 0;
}

void multiStageGraph(int stageNum, int *numPerStage)
{
    int i, q, p, weight, temp;
    memset(minRoad, 0x3f, sizeof(minRoad));           //初始化为一个充分大的数0x3f

    for (p = 0; p < numPerStage[0]; ++p)              //初始化源顶点层
    {
        minRoad[0][p] = 0;
    }

    for (i = 0; i < stageNum - 1; ++i)                //按段计算，终止与汇顶点的前一段
    {
        for (q = 0; q < numPerStage[i]; ++q)          //遍历第i段顶点
        {
            for (p = 0; p < numPerStage[i + 1]; ++p)  //遍历第i+1段顶点
            {
		printf("key in (%d,%d-%d) weight\n",i,q,p);
                scanf("%d", &weight);                 //读取边(q,p)的权重w(q,p)
                if (weight != -1)                     //存在边(q,p)
                {
                    temp = minRoad[i][q] + weight;
                    if (temp < minRoad[i+1][p])       //发现s到o的更短路径
                    {
                        minRoad[i+1][p] = temp;
                    }
                }
            }
        }
    }
    printf("%d\n", minRoad[stageNum-1][0]);

}
