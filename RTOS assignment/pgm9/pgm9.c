/*---------------------------------------------------------------------------------------------------------------------------------
9.	Create a telephone directory, with the first name, last name and telephone number. Provide the facility to order the 
entries of the directory according to the alphabetical ordering of the first name or based on the telephone number. 
Get the data from a file and use switch -case in your program. Provide user option to view entries ordered based on 
name or number. 
----------------------------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<string.h>

struct directory
{
	char firstName[50];
	char lastName[50];
	char number[20];
};

void orderByName(struct directory entries[50],int n);
void orderByNumber(struct directory entries[50],int n);
//void display();

int main()
{
	FILE *book;
	int sel,i=0;
	struct directory entries[50];
	
	book = fopen("directory.txt","r+");
	while(fscanf(book,"%s %s %s",&entries[i].firstName,&entries[i].lastName,&entries[i].number) != EOF)
		i++;
	do
	{
		printf("\nSelect your choice:\n\n");
		printf("1.Order by name\n");
	    printf("2.Order by number\n");
	    printf("3.Press 3 to exit.\n");	
	    scanf("%d",&sel);
	    
	    switch(sel)
	    {
	    	case 1: orderByName(entries,i);
	    			break;
	    	case 2: orderByNumber(entries,i);
	    			break;
	    	case 3: return;
	    	default: printf("\nInvalid choice\n");
		}
	}while(1);
	
	return 0;
}
void orderByName(struct directory entries[50],int n)
{
	FILE *book;
	int i,j;
	struct directory temp;
	
	for(j=0;j<n;j++)
	{
		for(i=0;i<n-1;i++)
		{
			if(strcmp(entries[i].firstName,entries[i+1].firstName) >0)
			{
				temp = entries[i];
				entries[i] = entries[i+1];
				entries[i+1] = temp;
			}
		}
	}
	book = fopen("directory.txt","w+");
	for(i=0;i<n;i++)
	{
		fprintf(book,"%s %s %s\n",entries[i].firstName,entries[i].lastName,entries[i].number);
		printf("%s %s %s\n",entries[i].firstName,entries[i].lastName,entries[i].number);
	}
	fclose(book);
}

void orderByNumber(struct directory entries[50],int n)
{
	FILE *book;
	int i,j;
	struct directory temp;
	
	for(j=0;j<n;j++)
	{
		for(i=0;i<n-1;i++)
		{
			if(strcmp(entries[i].number,entries[i+1].number) >0)
			{
				temp = entries[i];
				entries[i] = entries[i+1];
				entries[i+1] = temp;
			}
		}
	}
	book = fopen("directory.txt","w+");
	for(i=0;i<n;i++)
	{
		fprintf(book,"%s %s %s\n",entries[i].firstName,entries[i].lastName,entries[i].number);
		printf("%s %s %s\n",entries[i].firstName,entries[i].lastName,entries[i].number);
	}
	fclose(book);
}


