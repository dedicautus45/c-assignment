#include<stdio.h>
#include<string.h>

#define SIZE 10

typedef struct data DA;

struct data
{
	char opcode[SIZE];
	char op1[SIZE];
	char op2[SIZE];
};

int main()
{
	FILE *fp;
	DA input[SIZE];
	char c[30];
	int i=0,j,f = 0,a=0,b=0,d=0;
	
	if((fp = fopen("Ins.txt","r")) == NULL)
	{
		printf("Couldn't open\n");
		return 1;
	}
	
	while(fscanf(fp,"%[^\n]\n",c) != EOF)
	{
		for(a = 0; /*c[a] != ' '*/a < 3;a++)
		{
			input[i].opcode[a] = c[a];
			printf("sd = %c\n",input[i].opcode[a]);
		}
		input[i].opcode[a] = '\0';
		
		for(b = 0,a++; /*c[a] != ','*/a < 6;a++)
		{
			input[i].op1[b++] = c[a];
			printf("a= %c\n",input[i].op1[b]);
			b++;
		}
		input[i].op1[b] = '\0';
				
		for(d= 0,a++;a < 9;a++)
		{
			input[i].op2[d++] = c[a];
			
		}
		input[i].op2[d] = '\0';
		
		i++;
	}	
	fclose(fp);

	for(j = 0; j < i; j++)
	{
		
		if(!(strcmp(input[j].opcode,"\0") && strcmp(input[j].op1,"\0") && strcmp(input[j].op2,"\0")))
		{
			printf("Instruction %d is invalid.\n",j+1);
			if(!(strcmp(input[j].opcode,"\0")))
			{
				printf("Opcode is missing.\n");
			}
			else if(!(strcmp(input[j].op1,"\0")))
			{
				printf("Operand 1 is missing.\n");
			}
			else if(!(strcmp(input[j].op2,"\0")))
			{
				printf("Operand 2 is missing.\n");
			}
		}
		else
		{
			if(!strcmp(input[j].opcode,"ADD"))
			{
				if(( !strcmp(input[j].op1,"\0") && !strcmp(input[j].op2,"\0")))
				{
					printf("Instruction %d is invalid.\n",j+1);
				}
				else
				{
					printf("%s + %s\n",input[j].op1,input[j].op2);
				}	
			}
			else if(!strcmp(input[j].opcode,"SUB"))
			{
				if(( !strcmp(input[j].op1,"\0") && !strcmp(input[j].op2,"\0")))
				{
					printf("Instruction %d is invalid.\n",j+1);
				}
				else
				{
					printf("%s - %s\n",input[j].op1,input[j].op2);
				}	
			}
			else if(!strcmp(input[j].opcode,"MUL"))
			{
				if(( !strcmp(input[j].op1,"\0") && !strcmp(input[j].op2,"\0")))
				{
					printf("Instruction %d is invalid.\n",j+1);
				}
				else
				{
					printf("%s * %s\n",input[j].op1,input[j].op2);
				}	
			}
			else if(!strcmp(input[j].opcode,"DIV"))
			{
				if(( !strcmp(input[j].op1,"\0") && !strcmp(input[j].op2,"\0")))
				{
					printf("Instruction %d is invalid.\n",j+1);
				}
				else
				{
					printf("%s / %s\n",input[j].op1,input[j].op2);
				}	
			}
			else if(!strcmp(input[j].opcode,"MOV"))
			{
				if(( !strcmp(input[j].op1,"\0") && !strcmp(input[j].op2,"\0")))
				{
					printf("%d invalid.\n",j+1);
				}
				else
				{
					printf("Move %s to %s\n",input[j].op2,input[j].op1);
				}	
			}
			else if(!strcmp(input[j].opcode,"CJNE"))
			{
				if(( !strcmp(input[j].op1,"\0") && !strcmp(input[j].op2,"\0")))
				{
					printf("%d invalid.\n",j+1);
				}
				else
				{
					printf("compare %s to %s\n",input[j].op2,input[j].op1);
				}	
			}
			else
			{
				printf("undefined.\n");
			}
		}
	}
	
	return 0;
}

