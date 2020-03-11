#include<stdio.h>
void nzp(int a[],int n) 
{ 

	 int i; 

	  printf("\nvalues of array a are:\n"); 

	   for(i=0;i<n;i++) 

		    { 

			     if(a[i]<0) a[i]=0; 

			      printf("%d ",a[i]); 

			       } 

} 

int main() 

{ 

	 int b[5],i; 

	  printf("\ninput 5 numbers:\n"); 

	   for(i=0;i<5;i++) 

		    scanf("%d",&b[i]); 

	    printf("initial values of array b are:\n"); 

	     for(i=0;i<5;i++) 

		      printf("%d ",b[i]); 

	      nzp(b,5); 

	       printf("\nlast values of array b are:\n"); 

	        for(i=0;i<5;i++) 

			 printf("%d ",b[i]); 
	return 0;
} 
