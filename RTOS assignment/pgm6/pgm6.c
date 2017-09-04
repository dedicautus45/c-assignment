/*--------------------------------------------------------------------------------------------
Read a text file called input.txt and change all the characters to uppercase characters (Eg:
“ThisIsASampleText” should be changed to “THISISASAMPLETEXT”.
----------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp;
	char ch[100],temp[100];
	int i=0;
	
	fp = fopen("input.txt", "r");
	while(fscanf(fp,"%c",&ch[i])!=EOF)
	{
		temp[i]=ch[i];
		i++;
	}	
	temp[i]='\0';
	for (i=0;temp[i]!='\0';i++)
	{
		if('a'<=temp[i] && temp[i]<='z')
		{
		temp[i]=temp[i]-32;
		}
		
		
	}
	fclose(fp);
	fp = fopen("input.txt", "w");
	fprintf(fp,"%s",temp);
	fclose(fp);
	
}
