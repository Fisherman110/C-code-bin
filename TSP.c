#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <strings.h>
#define MAX_N 10
 
int mypow(int x, int y)
{
return (int)pow((double)x,(double)y);
}
 
struct path
{
int current;
int cost;
long set;//2 bits for vector
//struct path *lastNode;
struct path *lastNode;
struct path *next;
};
struct path *D[MAX_N];
 
/*下面三个函数是集合中子集的相关操作，集合利用2进制代码来表示
*比如包含n个元素的集合，将这n个元素从1到n标记，利用二进制中的相对应的位表示。
*如果第k位是1代表，元素k包含在这个子集中，如果为0表示不在这个子集中。
*/
/*功能是判断元素i是否在子集set中。
*采用按位与的方法，判断是否在set中
*返回1表示存在，返回0表示不存在
*/
int inSet(int i, int set)
{
if((mypow(2,i-1)&set)>0)
   return 1;
else
   return 0;
}
/*功能是向集合set中添加元素i
*将set的第i位设置为1，表示i被添加到了set中
*/
int insertSet(int i,int set)
{
if(inSet(i,set)==0)
   return set|mypow(2,i-1);
return set;
}
/*功能是从集合set中删除元素i
*将set的第i位设置为0，表示从set中删除了
*/
int deleteSet(int i, int set)
{
if(inSet(i,set))
{
   set = ~(mypow(2,i-1))&set;
}
return set;
}
/*功能是递归打印路径
*/
void print_path(struct path *p)
{
if(p==NULL)
{
   printf("1");
   return;
}
print_path(p->lastNode);
printf("->%d",p->current+1);
}
/*
*功能：计算最短路径的长度和最短路径
*方法：
*1,记n个城市为1，2，…，n. 对于给定的集合S等于{2,3,...n}和k属于S。
*2,记C(S,k)是由城市1出发，遍历S中每个城市恰好一次，最后终止在城市k的最优费用.
*3,当S中只有一个元素k时，C(S，k)= d(1,k)
* 当S中有多于一个元素时,C(S，k)等于任意一个属于S-k集合的子集m，C(s-k,m)+d(m,k)中最小的一个，
*4,这一方程的求解要求对一切给定大小的集合S及S中的每个可能的元素k，计算 C(S，k）的值
*5,当S等于{2,3,...n}时，如果C(S，k)的值对k属于S都已经通过计算得到，则最优环游的最小费用为
    C(S,k)+d(k,1)中最小的一个。
*PS:C(S,k)用struct path结构来表示set = S, current = K, cost = C(S,K)
*/
int tsp(int n, int (*a)[MAX_N])
{
int i,j;
struct path *temp,*p;
struct path **address;
long set;
int cost;
long mincost;
struct path *lastNode;
D[1] = NULL;
//当S中只有一个元素k时，C(S，k)= d(1,k)
for(i=1;i<n;i++)
{
   temp = malloc(sizeof(struct path));
   temp->current = i;
   temp->cost = a[0][i];
   temp->lastNode = NULL;
   temp->next = D[1];
   temp->set = mypow(2,i-1);
   D[1] = temp;
}
//循环n-2遍,每次构造集合包含J个元素的子集
for(j=2;j<n;j++)
{
   D[j] = NULL;//子集元素个数为J个的所有C(S,k)的链表的头
   for(i=1;i<n;i++)
   {
    //利用address保存C(S,K)的信息。即保存相应struct path结构的地址
    address = malloc(sizeof(struct path *)*mypow(2,n-1));
    bzero(address,sizeof(&address));
    p = D[j-1];
    while(p!=NULL)
    {
     //判断元素i是否已经在p->set集合中
     //如果在这个集合中了不能利用元素i和p->set构建新的子集了。
     //因为每个子集中的元素是唯一
     if(inSet(i,p->set)==0)
     {
      //当S中有多于一个元素时,C(S，k)等于任意一个属于S-k集合的子集m，C(s-k,m)+d(m,k)中最小的一个，
      set = insertSet(i,p->set);
      //判断C(S,k)是否已经计算过
      //如果计算过，比较cost值，取小的
      //不存在的话，就创建一个结构体struct path保存C(S,k)的信息
      if(address[set]!=NULL&&address[set]->current==i)
      {
       cost = p->cost + a[p->current][i];
       if(cost< address[set]->cost)
       {
        address[set]->cost = cost;
        address[set]->lastNode = p;
       }
      }
      else
      {
       temp = malloc(sizeof(struct path));
       temp->current = i;
       temp->cost = p->cost + a[p->current][i];
       temp->set = set;
       temp->lastNode = p;
       temp->next = D[j];
       D[j] = temp;
       address[set]=temp;
      }
     
     }
     p = p->next;
    }
    free(address);
   }
}
//这一方程的求解要求对一切给定大小的集合S及S中的每个可能的元素k，计算 C(S，k）的值
//当S等于{2,3,...n}时，如果C(S，k)的值对k属于S都已经通过计算得到，则最优环游的最小费用为
//C(S,k)+d(k,1)中最小的一个。
mincost = -1;
p = D[n-1];
while(p)
{
   if(mincost==-1 || mincost > p->cost + a[p->current][0])
   {
    mincost = p->cost + a[p->current][0];
    lastNode = p;
   }
   p = p->next;
}
//打印计算结果
printf("mincost=%d\n",mincost);
//打印路径
print_path(lastNode);
printf("->1\n"); 
return mincost;
}
 
int main(int argc, char *argv[])
{
int a[MAX_N][MAX_N]=
   { { 0, 10, 20, 30, 40, 50},
    {12, 0, 18, 30, 25, 21},
    {23, 19, 0, 5, 10, 15},
    {34, 32, 4, 0, 8, 16},
    {45, 27, 11, 10, 0, 18},
    {56, 22, 16, 20, 12, 0}
   };
int n = 6;
tsp(n,a);
return EXIT_SUCCESS;
}
