#include<stdio.h>

void main()
{
 char a;
 printf("enter a character:");
 scanf("%c",&a);

 if(a>=65&&a<=90)
   printf("%c",a+32);
 else
   printf("wrong entry");
}


