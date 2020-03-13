#include<stdio.h>
void cpystr(char *pss,char *pds);
int main(){
	char *pa="CHINA",b[10],*pb;
	pb=b;
	cpystr(pa,pb);
	printf("string a=%s\nstring b=%s\n",pa,pb);

	return 0;
}

void cpystr(char *pss,char *pds){
	while((*pds=*pss)!='\0'){
		pds++;
		pss++;
	}
}
