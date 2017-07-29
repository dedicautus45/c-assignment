#include<stdio.h>
#include<assert.h>
int main()
{
   int no[3],n,i;
 
   printf("Enter the number of terms\n");
   scanf("%d",&n);
   printf("enter the elements\n");
   for(i=0;i<=n;i++)	
   scanf("%d",&no[i]); 
   if(no[n]==(no[n-1]+no[n-2]))
   printf("no's are from fibo series\n");
   else 
   printf("not from fibo series\n");
   
return 0;
   
}
