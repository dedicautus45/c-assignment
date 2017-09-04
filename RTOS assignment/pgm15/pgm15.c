/*-----------------------------------------------------------------------------------------------------



-------------------------------------------------------------------------------------------------------*/


#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp,*output;
	char ch[400];
	int i=0;

	output = fopen("output.txt","w");
	fclose(output);	
		
	fp = fopen("input.txt", "r");

	while(fscanf(fp,"%c",&ch[i])!=EOF)
	{
			printf("%c",ch[i]);
		if(ch[i] == 'F')
		{
			output = fopen("output.txt","a");
			fprintf(output,"%c",' ');
			fclose(output);
		}
		else
		{
			output = fopen("output.txt","a");
			fprintf(output,"%c",ch[i]);
			fclose(output);
		}
		
	i++;	
	}	

	fclose(fp);
	
}
