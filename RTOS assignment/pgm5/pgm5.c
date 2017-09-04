/*----------------------------------------------------------------------------------------------------------------
Read a text file called input.txt and segregate the even (2 nd ,4 th , 6 th …) and odd (1 st ,3 rd ,5 th …) words
into two different files names even.txt and odd.txt. Get the names of input and output files
through command line arguments.
------------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
void main(int argc, char *argv[])
{
	FILE *fp, *odd, *even;
	char ch[100];
	int i=1;
	
	odd = fopen(argv[3],"w");
	fclose(odd);
	even = fopen(argv[2],"w");
	fclose(even);

	fp = fopen(argv[1], "r");
	if(fp==NULL)
	{
		printf("Could not find the file %s",argv[1]);
		return;
	}

	while(fscanf(fp,"%c",&ch[i])!=EOF)
	{
		if(i%2==1)
		{
			odd = fopen(argv[3],"a");
			fprintf(odd,"%c",ch[i]);
			fclose(odd);
		}
		if(i%2==0)
		{
			even = fopen(argv[2],"a");
			fprintf(even,"%c",ch[i]);
			fclose(even);
		}
		i++;
	}	

	fclose(fp);
	
}
