#include<stdio.h>
#include<string.h>

struct date
{
	int month;
	int day; 
	int year; 
};

struct stu{
	int num;
	char name[20];
	char gender;
	struct date birthday;
	float score;
};
int main(){
	struct stu s2,s3;
	struct stu s1={20201,"张三",'m',{6,23,2000},98.5};
	s2=s1;
	//s3.name="李四";
	strcpy(s3.name,"李四");

	printf("s3'name is:%s",s3.name);
	printf("s2'name is :%s",s2.name);
	printf("%d %s %c %d %d %d %f",s1.num,s1.name,s1.gender,s1.birthday.month,s1.birthday.day,s1.birthday.year,s1.score);
	return 0;
}
