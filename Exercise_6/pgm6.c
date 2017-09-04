/*********************************************************/
/*6. Write a program to check whether two files are same.*/
/*********************************************************/
#include <stdio.h>
int main()
{
	FILE* fp1,*fp2;
	char file1[20],file2[20];
	printf("\nEnter two file to compare");
	scanf("%s%s",file1,file2);
	fp1 = fopen(file1,"r");
	printf("\n%s %s",file1,file2);
	if (fp1==NULL)
	{
		printf("\n%s not found",file1);
	}
	fp2 = fopen(file2,"r");
	if (fp2==NULL)
	{
		printf("\n%s not found",file2);
	}
	while((fscanf(fp1,"%s",file1)!=EOF)&&(fscanf(fp1,"%s",file2)!=EOF))
	{
		if (!(strcmp(file1,file2)))
		{
			printf("\nBoth files are not same");
			return 0;
		}
	}
	printf("\nBoth file are same\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}