#include <stdio.h>

int main ()
{
	int n,a,b=0;
        printf("Enter number \n");
	scanf("%d",&n);

while (n>0)

{
a=n%10;
b=b+a;
n=n/10;
}
 printf("\n The sum is : %d  \n",b);
}

