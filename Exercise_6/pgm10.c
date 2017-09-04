/*******************************************************************************/
/*10. Files ‘A’ and ‘B’ contains some numbers in sorted order. Merge two files*/
/*    into one ( either A or B) so that merged file contains entries of two    */
/*    files in a sorted order.                                                */
/******************************************************************************/
#include <stdio.h>
#include <assert.h>
int main()
{
	FILE *A,*B;
	unsigned int i,j=0,k=0,num,temp,numArr[100];
	A = fopen("A.txt","r+");
	assert(A!=NULL);
	B = fopen("B.txt","r");
	assert(B!=NULL);
	while(fscanf(A,"%d",&num)!=EOF)
	{
		numArr[j] = num;
		j++;
	}
	fflush(stdin);
	i =j;
	while(fscanf(B,"%d",&num)!=EOF)
	{
		numArr[i] = num;
		i++;
	}
	
	for(j=0;j<i;j++)
	{
		for (k=j; k<=i;k++ )
		{
			if (numArr[j]<numArr[k])
			{
				temp = numArr[j];
				numArr[j] = numArr[k];
				numArr[k] = temp;
			}
		}
	}
	rewind(A);
	j = 0;
	while(j!=i+1)
	{
		fprintf(A, "%d\n",numArr[j] );
		j++;
	}	

	return 0;
}