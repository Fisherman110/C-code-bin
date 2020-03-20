#include<stdio.h>

struct stu
{
	int num;
	char name[20];
	float score;
	char gender;
};

int main(){
	struct stu s[5]={
		{20201,"张一",98.5,'m'},
		{20202,"张二",67.3,'f'},
		{20201,"张三",94.5,'m'},
		{20201,"张四",32.59,'f'},
		{20201,"张五",87.5,'m'}
		};
	float ave,sum;
	for(int i=0;i<5;i++)
	{
		sum+=s[i].score;
	}
	ave=sum/5;

	printf("averege is:%f",ave);

	return 0;
}
