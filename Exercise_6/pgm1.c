/*********************************************************************/
/*1. Write a simple program to display the contents of a file.      */
/********************************************************************/
#include <stdio.h>
int main()
{
	FILE*fp;
	char ch[500],fileName[20];
	printf("\nEnter file Name");
	scanf("%s",fileName);
	fp = fopen(fileName,"r");
	if (fp == NULL)
	{
		printf("\nFile not found\n" );
	}
	while(fscanf(fp,"%s",ch)!=EOF)
	{
		printf("%s",ch);
	}
	return 0;
}