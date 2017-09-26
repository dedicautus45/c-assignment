#include <stdio.h>
//#include<assert.h>
main ()
{
	float u,v,t,d,a;
        int c;
        printf("Enter the speed\n");
	scanf("%f",&u);
	printf("enter choice");
	scanf("%d",&c);
	u=0.2777778*u;//convert speed to ms
        
switch(c)
{  case 1: printf("enter time\n");
	   scanf("%f",&t);
	   printf("Enter the speed\n");
	   scanf("%f",&v);
	   v=0.2777778*v;
	   d=((u+v)/2)*t;
	   if(30>d)
	   printf("collision");
	   else
	   printf("no collosion");
	   break;
   
   case 2: printf("enter acc\n");
	   scanf("%f",&a);
	   printf("Enter the speed\n");
	   scanf("%f",&v);
	   v=0.2777778*v;
	   d=(((v*v)-(u*u))/(2*a));	
           if(d<1400)
	   printf("safe landing");
	   else
	   printf("unsafe");
	   break;
   default: ;
}
}

