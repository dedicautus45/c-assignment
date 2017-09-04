/*****************************************************************/
/*2. Write a program to copy the contents of one file to another.*/
/****************************************************************/
#include <stdio.h>
int main()
{
	FILE*fpin,*fpout;
	char fileName[20],ch;
	printf("\nEnter file Name");
	scanf("%s",fileName);
	fpin = fopen(fileName,"r");
	fpout = fopen("output.txt","w");
	while(fscanf(fpin,"%c",&ch)!=EOF)
	{
		fprintf(fpout, "%c",ch );
	}
	return 0;
}