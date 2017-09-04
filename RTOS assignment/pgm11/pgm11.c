#include<stdio.h>

int main()
{
	int n,fact = 1,i;

	printf("Enter a number to find the factorial: ");
	scanf("%d",&n);

	for(i=n;i>=1;i--)
		fact = fact * i;

	printf("\n%d! = %d\n",n,fact);

	return 0;
}
