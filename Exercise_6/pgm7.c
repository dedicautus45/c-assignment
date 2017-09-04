/*****************************************************************************************************************************/
/*7. Write ‘n’ numbers into file. Write a function to sort the file in descending order. Don’t use arrays or temporary files.*/
/*****************************************************************************************************************************/
#include <stdio.h>
#include <assert.h>
unsigned int fileSort(FILE*,char[]);
int main()
{
	FILE *fp;
	unsigned int index,num;
	char fileName[20]; 
	printf("\nEnter file Name");
	scanf("%s",fileName);
	fp = fopen(fileName,"w");
	assert(fp!=NULL);
	printf("\nHow many numbers you want to write in %s",fileName);
	scanf("%d",&index);
	printf("\nEnter %d numbers",index);
	for (int i = 0; i < index; i++)
	{
		scanf("%d",&num);
		fprintf(fp, "%d\n",num );
	}
	rewind(fp);
	fileSort(fp,fileName);
	return 0;
}
unsigned int fileSort(FILE*fp,char fileName[])
{
	unsigned int num,i=0,j=0,k=0,num1;
	long int temp,index=0;
	fseek(fp,0,SEEK_END);
	index = ftell(fp);
	rewind(fp);
	fclose(fp);
	for (i = 0; i<=index; i++)
	{

		for (j = i+1; j<=index+i; j++)
		{
			
			fp = fopen(fileName,"r");
			//fseek(fp,i,SEEK_SET);
			fseek(fp,i,SEEK_SET);
			fscanf(fp,"%d",&num);
			//num = getw(fp);
			//fseek(fp,j,SEEK_SET);
			fseek(fp,j,SEEK_SET);
			fscanf(fp,"%d",&num1);
			//num1 = getw(fp);
			printf("\n%d\t%d",num,num1);
			fclose(fp);
			fp = fopen(fileName,"r+");
			if (num<num1)
			{
				
				fseek(fp,i,SEEK_SET);
				//fscanf(fp,"%d",&num);
				fprintf(fp," %d\n",num1);
				//putw(num1,fp);
				fseek(fp,j,SEEK_SET);
				//fscanf(fp,"%d",&num1);
				fprintf(fp," %d\n",num);
				//putw(num,fp);
				//fclose(fp);

			}
			fclose(fp);
		}
	}
	
}