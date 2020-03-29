#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * bigmuilty(char*muiltied,int len1,char *muilty,int len2)//muiltied 为被乘数，len1为
{//其长。muilty为乘数，len2为其长
   int len;
   int i=0;
   int j=0;
   int k=0;
   int tmp_result=0;
   int carry=0;
   char* result;

   len=len1+len2; //两个数相乘他们的最大长度为乘数与被乘数的长度和
   result=(char*)calloc(len,1);//动态分配内存
   for(i=0;i<len2;i++)//用乘数的每一位去乘以被乘数
   {
     for(j=0;j<len1;j++)
     {
        tmp_result=muilty[len2-i-1]*muiltied[len1-j-1];//得到零时结果
        result[j+i]+=tmp_result;//如果以0为起始标号，被乘数和乘数下标分别从右往左依次增加，则结果
       //存放的位置为j+i
     }
     for(k=0;k<=j+i-1;k++)//整理结果
     {
               
        if(result[k]>1)
        {
           carry=result[k]/2;
           result[k]=result[k]%2;
           result[k+1]+=carry;
        }
     }
   }
return result;
}
int main()
{
   int len1=0;
   int len2=0;
   int len;
   int i=0;
   int num='0';
   char *result;

    char *a,*b;
    char ch;
    FILE *fp;

    if((fp=fopen("./整数","rt"))==NULL)
	{
		printf("errors occur in open 整数\n");
		exit(1);
	}

	ch=fgetc(fp);
	while(ch!='\n')
	{
		if(ch=='#')
		{
			len1=len2;
			len2=0;
			ch=fgetc(fp);
			continue;
		}
		len2++;
		ch=fgetc(fp);
	}
	printf("%d %d",len1,len2);
	rewind(fp);
	
	a=(char *)malloc(len1*sizeof(char));
	b=(char *)malloc(len2*sizeof(char));
	//char x[n+1],y[m+1];
	
	
	ch=fgetc(fp);
	i=0;
	while(ch!='#')
	{
		a[i]=ch;
		i++;
		ch=fgetc(fp);
	}
	
	ch=fgetc(fp);
	i=0;
	while(ch!='\n')
	{
		b[i]=ch;
		i++;
		ch=fgetc(fp);
	}
	
	for(i=0;i<len1;i++)
		printf("%c",a[i]);

   len=len1+len2;
   for(i=0;i<len1;i++)
   {
       a[i]=a[i]-num;
   }
   for(i=0;i<len2;i++)
   {
      b[i]=b[i]-num;
   }
   result=bigmuilty(a,len1,b,len2);
   i=len-2;
   printf("\nresult : ");
   if(result[len-1]>0)
   {
     printf("%c",result[len-1]+num);
   }
   while(i>=0)
   {
      printf("%c",result[i]+num);
   i--;
   }
   printf("\n");
    fclose(fp);
    free(a);
    free(b);
   free(result);
   return 0;
}
