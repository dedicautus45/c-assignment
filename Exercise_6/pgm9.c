/************************************************/
/*9. Write a program to reverse the same file.**/
/***********************************************/
#include <stdio.h>
#include <assert.h>
int main()
{
	FILE *fp1,*fp2;
	char ch;
	unsigned int i=0,j=0;
	long int f,fcur;
	fp1 = fopen("file.txt","r");
	assert(fp1!=NULL);
	fp2 = fopen("file1.txt","w");
	assert(fp2!=NULL);
	while(fscanf(fp1,"%c",&ch)!=EOF)
	{
		j++;
	}
	
	while(i!=j+1)
	{
		fseek(fp1,-i,SEEK_END);
		
		fscanf(fp1,"%c",&ch);
		fprintf(fp2, "%c",ch );
		
		i++;
	}
	fcolse(fp1);
	fclose(fp2);

	return 0;
}
