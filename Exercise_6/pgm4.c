/************************************************************************************/
/*4. Write a program to count number of characters, spaces tabs and lines in a file.*/
/************************************************************************************/
#include <stdio.h>
int main()
{
	FILE*fp;
	char fileName[20],ch;
	unsigned int charCount=0,spaceCount=0,tabsCount=0,linesCount=0;
	printf("\nEnter file Name");
	scanf("%s",fileName);
	fp = fopen(fileName,"r");
	if (fp ==NULL)
	{
		printf("\nfile not found");
	}
	while(fscanf(fp,"%c",&ch)!=EOF)
	{
		if(ch==' ')
		{
			spaceCount++;
		}
		else if (ch=='\n')
		{
			linesCount++;
		}
		else if (ch=='\t')
		{
			tabsCount++;
		}
		else if((ch!=' ')&&(ch!='\n')&&(ch!='\t'))
		{
			charCount++;
		}
	}
	printf("\nNo.of characters=%d\nNo.of lines=%d\nNo.of spaces=%d\nNo.of tabs=%d\n",charCount,linesCount,spaceCount,tabsCount);
	return 0;
}