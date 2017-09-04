/****************************************************************************************************************/
/*5. Read a file which contains one number per line. Check the number is odd or even and write to corresponding */
/*     files. Note: Numbers may not be single digit numbers.                                                    */
/****************************************************************************************************************/
#include <stdio.h>
int main()
{
	FILE*fp,*fpodd,*fpeven;
	char fileName[10];
	int ch;
	
	printf("\nEnter file name");
	scanf("%s",fileName);
	fp = fopen(fileName,"r");
	if (fp==NULL)
	{
		printf("\n%s not found",fileName);
	}
	fpodd = fopen("odd.txt","w");
	if (fpodd==NULL)
	{
		printf("\nodd.txt not found");
	}
	fpeven = fopen("even.txt","w");
	if (fpeven==NULL)
	{
		printf("\neven.txt not found");
	}
	while((fscanf(fp,"%d",&ch))!=EOF)
	{
		
		if (ch%2)
		{
			fprintf(fpodd, "%d ",ch );
		}
		else if ((ch%2)==0)
		{
			fprintf(fpeven, "%d ",ch);
		}
	}
	fclose(fpodd);
	fclose(fp);
	fclose(fpeven);
	return 0;
}
