#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int RANDOMIZED_SELECT(int a[],int p,int r,int i);
int RANDOMIZED_PARTITION(int a[],int p,int r);
int PARTITION(int a[],int p,int r);
void swap(int *a,int *b);
int RANDOM(int p,int q);
int main()
{
	    int a[] = {10,9,8,7,6,5,4,3,2,1};
	    int i = 6;
	    printf("第%d小:%d\n",i,RANDOMIZED_SELECT(a,0,9,i));

            return 0;
}
void swap(int *a,int *b)
{
	    int temp;
	    temp = *a;
	    *a = *b;
	    *b = temp;
}
int RANDOM(int p,int q)
{
	    int i,number;
	    srand((unsigned)time(NULL));
	    number = rand()%(q-p+1)+p;
	    return number;
}
int PARTITION(int a[],int p,int r)//快排的部分
{
	    int x = a[r];
	    int i = p- 1;
	    for(int j = p;j<=r-1;j++)
	    {
	    	if(a[j] <= x)
		{
			i = i + 1;										                       swap(&a[j],&a[i]);										      } 
	    }
	    swap(&a[i+1],&a[r]);
	    return i+1;
}

int RANDOMIZED_PARTITION(int a[],int p,int r)//随机交换数字
{
	    int i = RANDOM(p,r);
	        swap(&a[r],&a[i]);
		    return PARTITION(a,p,r);
}

int RANDOMIZED_SELECT(int a[],int p,int r,int i)//选择算法核心
{
	if(p == r)
		return a[p];
	int q = RANDOMIZED_PARTITION(a,p,r);
	int k = q - p + 1;//证明a[q]之前有几个数字比它小
	if(i == k)//如果刚好等于i，输出
		return a[q];
	else if(i < k)//如果i比k小，证明要找的元素在低区
		return RANDOMIZED_SELECT(a,p,q-1,i);
	else //找的元素在高区
		return RANDOMIZED_SELECT(a,q+1,r,i-k);
         //因为a[q]已经是前面第k个小的，所以在后面就是i-k小   
}
