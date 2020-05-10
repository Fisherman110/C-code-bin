#include<stdio.h>
#include<stdlib.h>
#define BOOL int

void sort(int s[],int f[],int n)//把各个活动的起始时间和结束时间按结束时间递增排序
{
    int a,b;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(f[i]>f[j])
            {a=f[i];f[i]=f[j];f[j]=a;
            b=s[i];s[i]=s[j];s[j]=b;}
        }
    }
}


int activemanage(int s[],int f[],BOOL a[],int n)
{
    a[0]=1;
    int i;
    int j=0,count=1;
    for(i=1;i<n;i++)
    {
        if(s[i]>=f[j])
        {
            a[i]=1;
            j=i;
            count++;
        }
        else a[i]=0;
    }
    return count;
}

void main()
{
    int i,n;
    int p;
    int s[100],f[100];
    BOOL a[100];
    printf("输入节目数：\n");
    scanf("%d",&n);
    printf("请依次输入节目的开始和结束时间\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&s[i],&f[i]);
    }
    sort(s,f,n);
    p=activemanage(s,f,a,n);
    printf("安排的节目个数为:%d\n",p);
    printf("节目的选取情况为(0表示不选 1表示选取):\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
        printf("%d",s[i]);
        printf("----->");
        printf("%d\n",f[i]);
    }
    printf("\n");
}