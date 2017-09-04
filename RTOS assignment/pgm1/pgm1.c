/*-------------------------------------------------------------------------------------------
Get ten numbers from user. Store them in an array. Using functions, find sum, average and
product of the numbers. Print the sum, average and product in the main function.
---------------------------------------------------------------------------------------------*/

#include<stdio.h>

void sum(int []);
void average(int []);
void product(int []);

int main(){
	
	int num[10],i;

	printf("Enter 10 numbers: \n");
	for(i=0;i<10;i++)
		scanf("%d",&num[i]);

	sum(num);
	average(num);
	product(num);

	return 0;
}

void sum(int arr[])
{
	int sum=0,i;
	for(i=0;i<10;i++)
		sum = sum + arr[i];

	printf("\nSum of given 10 numbers is: %d\n",sum);
}
void average(int arr[])
{
	int i,sum=0;
	float avg;
	for(i=0;i<10;i++)
		sum = sum + arr[i];

	avg = (float)sum / 10;
	printf("\nAverage of given 10 numbers is: %f\n",avg);
}
void product(int arr[])
{
	long prod = 1;
	int i;

	for(i=0;i<10;i++)
		prod = prod * arr[i];

	printf("\nProduct of given 10 numbers is: %ld\n",prod);
}