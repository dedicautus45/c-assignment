/*--------------------------------------------------------------------------------------------
Read a text stored in a file. Count the number of words and lines in the file. Use functions.
----------------------------------------------------------------------------------------------*/

#include<stdio.h>

int characterCount();
int linesCount();

void main()
{
	int charCount, lineCount;
	
	lineCount = linesCount();
	charCount = characterCount();
	
	printf("\n Character count = %d",charCount);
	printf("\n Lines count = %d",lineCount);
}
int characterCount()
{
	int charCount = 0;
	char character[30];
	FILE *fp;
	
	fp = fopen("pgm4.txt","r");
	while(fscanf(fp,"%s",&character)!=EOF)
		charCount++;
	fclose(fp);
	return charCount;
}

int linesCount()
{
	int lineCount = 0;
	char character;
	FILE *fp;
	
	fp = fopen("pgm4.txt","r");
	while(fscanf(fp,"%c",&character)!=EOF)
	{
		if(character == '\n')
			lineCount++;
	}
	fclose(fp);
	return lineCount+1;
}
