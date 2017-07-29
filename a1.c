#include <stdio.h>
#include <assert.h>
int leap(int);
int main ()
{
	int y;
	printf("Enter the year:\n");
	scanf("%d",&y);
	assert(leap(y)!=0);
	if (y%4==0 || y%100==0 && y%400==0)
	printf("The year is a leap year");
	else 
	printf("The year is not a leap year");
        	
}
int leap(int y)
{ int r;
r=(y%4==0 || y%100==0 && y%400==0);
return r;
}

