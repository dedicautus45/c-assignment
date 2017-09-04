/*---------------------------------------------------------------------------------------------
Compare two dates and display the latter one. Consider the date as consisting of day, month
and year. Get the dates through user inputs through console. Use structures in this program.
----------------------------------------------------------------------------------------------*/

#include<stdio.h>

typedef struct date
{
	int dd,mm,yyyy;

}DATE;

void display(struct date d1);

int main()
{
	DATE d1,d2;

	printf("\nEnter first date in dd mm yyyy format:");
	scanf("%d %d %d",&d1.dd,&d1.mm,&d1.yyyy);
	printf("\nEnter second date in dd mm yyyy format:");
	scanf("%d %d %d",&d2.dd,&d2.mm,&d2.yyyy);

	if(d1.yyyy > d2.yyyy)
		display(d1);
	else if(d1.mm > d2.mm)
		display(d1);
	else if(d1.dd > d2.dd)
		display(d1);
	else 
		display(d2);
	
	return 0;
}

void display(struct date d1)
{
	printf("The latter date is: %d-%d-%d\n",d1.dd,d1.mm,d1.yyyy);
}
