#include <stdio.h>
#include<assert.h>
int sum(int n)
{int a,b=0;
while (n>0)
{
a=n%10;
b=b+a;
n=n/10;
}
return b;
}
main()
{
	int n;
        printf("Enter number \n");
	scanf("%d",&n);
	assert(sum(131)==5);
        printf("\n The sum is : %d  \n",sum(n));
}

