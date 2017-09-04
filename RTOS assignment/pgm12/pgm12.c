/*---------------------------------------------------------------------------------------------------------------------------------
12.	Write a C program to read input.txt file to obtain information about the students such as name, course and marks. 
Use structures in the program. Display the names of students according to the ascending order of marks. 
Also find out grade of the student which is based on the marks of the student and accordingly write Grade of the student 
along with the student names into output.txt. Grade calculation may be done as below.
Marks > = 90 then Grade = 'A', 
Marks > = 70 and Marks < 90 then Grade = 'B', 
Marks > = 40 and Marks < 70 then Grade = 'C',
Else Grade = 'D'
----------------------------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>


//void findGrade(struct ,int );

struct student
{
	char name[100];
	char course[100];
	int marks;
	char grade;
};

void sorting(struct student Student[],int );
void findGrade(struct student Student[],int );

int main()
{
	FILE *input;
	struct student Student[50];
	int i=0;
	
	input = fopen("input.txt","r");
	while(1)
	{
		fscanf(input,"%s %s %d ",&Student[i].name,&Student[i].course,&Student[i].marks);
		//printf("%s %s %d\n",Student[i].name,Student[i].course,Student[i].marks);
		i++;
		if(feof(input))
			break;
	}
	fclose(input);
	
	sorting(Student,i);
	findGrade(Student,i);
	return 0;
}

void sorting(struct student Student[50],int n)
{
	
	struct student temp;
	int i,j;
	printf("Before sorting: \n");
	for(j=0;j<n;j++)
	{
		printf("%s %s %d\n",Student[j].name,Student[j].course,Student[j].marks);
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<(n-1);i++)
		{
			if(Student[i].marks < Student[i+1].marks)
			{
				temp = Student[i];
				Student[i] = Student[i+1];
				Student[i+1] = temp;
			}
		}
	}
	printf("\n\nAfter sorting:\n");
	for(j=0;j<n;j++)
	{
		printf("%s %s %d\n",Student[j].name,Student[j].course,Student[j].marks);
	}
	
}

void findGrade(struct student Student[50],int n)
{
	FILE *output;
	int j;
	output = fopen("output.txt","w+");
	for(j=0;j<n;j++)
	{
		if(Student[j].marks >= 90)
			Student[j].grade = 'A';
		else if(Student[j].marks >= 70)
			Student[j].grade = 'B';
		else if(Student[j].marks >= 40)
			Student[j].grade = 'C';
		else 
			Student[j].grade = 'D';

		fprintf(output,"%s %s %d %c\n",Student[j].name,Student[j].course,Student[j].marks,Student[j].grade);
	}
	fclose(output);
}

