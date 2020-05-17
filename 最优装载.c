#include<stdio.h>
#define N 10
void Load(float *,int *);
float c;
int main(){
	float w[10]={9.9,6.3,90.6,32.3,54.1,8.0,45.7,12.0,8.7,3.4};
	int x[10]={0};
	int result;
	float weight;
	c=150;

	Load(w,x);
	for(int i=0;i<N;i++)
		result+=x[i];
	printf("%d\n",result);
	for(int i=0;i<N;i++)
		printf("%d ",x[i]);
	printf("\n");
	for(int i=0;i<N;i++){
		weight+=x[i]*w[i];
	}
	printf("%f",weight);
	

	return 0;
}

void Load(float *w,int *x)
{
	float temp;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(w[i]>w[j]){
				temp=w[i];
				w[i]=w[j];
				w[j]=temp;
			}		
		}
	}

	for(int i=0;i<N && c>0;i++){
		if(c>=w[i]){
			x[i]=1;
			c-=w[i];
		}
	}
};
