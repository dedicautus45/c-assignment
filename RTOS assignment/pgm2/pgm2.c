/*-------------------------------------------------------------------------------------------
Get ten numbers from user. Store them in an array. Using functions, find sum, average and
product of the numbers. Print the sum, average and product in the main function.

Modify the above program to continue to accept the input from the user until the user enters
‘999’. As the user inputs the number, the sum, average and product should be displayed in the
main function.
---------------------------------------------------------------------------------------------*/

#include<stdio.h>

int sum(int []);
float average(int []);
long int product(int []);

int main(){
	
	int num[100],i;

	printf("Enter numbers. And enter number 999 to end taking numbers.\n");
	for(i=0; ;i++)
	{
		scanf("%d",&num[i]);
		if(num[i] == 999)
			break;
	}
	
	printf("\nSum of given numbers is: %d\n",sum(num));
	printf("\nAverage of given numbers is: %f\n",average(num));
	printf("\nProduct of given numbers is: %ld\n",product(num));

	return 0;
}

int sum(int arr[])
{
	int sum=0,i;
	for(i=0; ;i++)
	{
		sum = sum + arr[i];
		if(arr[i] == 999)
			break;
	}
	
	return sum;
}
float average(int arr[])
{
	int i,sum=0;
	float avg;
	for(i=0; ;i++)
	{
		sum = sum + arr[i];
		if(arr[i] == 999)
			break;
	}

	avg = (float)sum / (i+1);
	return avg;
}
long int product(int arr[])
{
	long prod = 1;
	int i;

	for(i=0; ;i++)
	{
		prod = prod * arr[i];
		if(arr[i] == 999)
			break;
	}

	return prod;
}
