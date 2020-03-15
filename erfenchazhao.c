#include<stdio.h>
#define N 12
int main(){
	int a[N],low,high,i,mid,x;
	printf("key in 12 nums:\n");
	for(i=0;i<N;i++)
	{	
		scanf("%d",&a[i]);
	}
	printf("key in a num you want to search:\n");
	scanf("%d",&x);
	low=a[0];
	high=a[N-1];
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x<a[mid]){
			high=mid+1;
		}
		else if(x==a[mid]){
			printf("get by %d",mid);
			break;
		}else{
			low=mid-1;
		}
	}

	return 0;
}
