#include <stdio.h>
#include<assert.h>
int power(int n,int m)
{int i,p=1;
for(i=0;i<m;i++)
p*=n;
return p;
}
main()
{
int n,p;
printf("Enter the no and power\n");
	scanf("%d %d",&n,&p);
assert(power(n,p)==(int)32);
printf("%d",power(n,p));
}
