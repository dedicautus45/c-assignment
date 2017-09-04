/*-----------------------------------------------------------------------------------------------------



-------------------------------------------------------------------------------------------------------*/


#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp,*even,*odd;
	int num;

	odd = fopen("odd.txt","w");
	fclose(odd);
	even = fopen("even.txt","w");
	fclose(even);
	
	fp = fopen("input.txt", "r");

	while(fscanf(fp,"%d",&num)!=EOF)
	{
		if(num%2==0)
		{
			even = fopen("even.txt","a");
			fprintf(even,"%d ",num);
			fclose(even);
		}
		else
		{
			odd = fopen("odd.txt","a");
			fprintf(odd,"%d ",num);
			fclose(odd);
		}
		
		
	}	

	fclose(fp);
	
}
