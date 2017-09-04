/*-----------------------------------------------------------------------------------------------------



-------------------------------------------------------------------------------------------------------*/


#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp,*output;
	int num;

	fp = fopen("input.txt", "r");

	while(fscanf(fp,"%d",&num)!=EOF)
	{
		if(num%8==0)
		{
			output = fopen("output.txt","w");
			fprintf(output,"%d",1);
			fclose(output);
		}
		else
		{
			output = fopen("output.txt","w");
			fprintf(output,"%d",0);
			fclose(output);
		}
		
		
	}	

	fclose(fp);
	
}
