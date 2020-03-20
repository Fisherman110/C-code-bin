#include<stdio.h>
#include<stdlib.h>
struct stu
{
	int num;
	char *name;
	char gender;
	float score;
};
int main(){
	struct stu *ps;
	ps=(struct stu*)malloc(sizeof(struct stu));//申请动态内存
	ps->num=20201;
	ps->name="zhangsan";
	ps->gender='M';
	ps->score=89.4;

	printf("%s",ps->name);

	free(ps);//释放内存空间
	return 0;
}
