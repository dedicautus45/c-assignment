/*--------------------------------------------------------------------------------------------------------
Read a string from a file. Count the number of characters in a given string without making use of
the string library function. Use ‘for loop’. Get the input using ‘fscanf’. Use functions and pass
string by reference.
----------------------------------------------------------------------------------------------------------*/

#include<stdio.h>

int countCharacters(char *str);
int count=0;

int main()
{
	FILE *fp;
	int i=0;
	char str[100];

	fp = fopen("pgm3.txt","r");

	for(;fscanf(fp,"%s",str) != EOF;){
		printf("%s ", str );  
		countCharacters(str);
	}
	
	fclose(fp);
	printf("\nThe number of characters in the given string is %d\n",count);
	return 0;
}
int countCharacters(char *str)
{
	int i=0;
	while(str[i] != '\0')
	{
		count++;
		i++;
	}
	return 1;
}