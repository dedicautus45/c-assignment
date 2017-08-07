#include<stdio.h>
int sum(int [],int);
float avg(int ,int );
int prod(int [],int);
main()
{
int no[5],i,s,p;
float a;
printf("enter no\n");
for(i=0;i<=5;i++)
scanf("%d",&no[i]);
s=sum(no,5);
a=avg(s,5);
p=prod(no,5);
printf("sum %d \n avg %f \n prod %d \n",s,a,p);
}
int sum(int n[],int e)
{ int s=0,i;
for(i=0;i<=e;i++)
{
s+=n[i];
}
return s;
}
float avg(int n,int e)
{
float a=0;
a=n/e;
return a;
}
int prod(int n[],int e)
{
int p=1,i;
for(i=0;i<=e;i++)
{
p*=n[i];
}
return p;
}
