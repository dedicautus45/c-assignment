#include<stdio.h>
#include<string.h>
#include<stddef.h>
int max(int m,int n)
{
	int max;
	max=n;
	if(m>max)
	{
		max=m;
	}
	return max;
}
int main()
{
	FILE *in,*out;
	in=fopen("input.txt","r");
	if(in==NULL)
	{
		printf("input.txt failed to open\n");
		return 1;
	}
	out=fopen("output.txt","w");
	if(in==NULL)
	{
		printf("output.txt failed to open\n");
		return 1;
	}
	int i=0,j=0,line[10],Register[10],lcount;
	int l,m,n;
	char str[15][10],op[15][10],c;
	while((fscanf(in,"%s %s",str[j],op[j]))!=EOF)
	{
		j++;
	}
	lcount=j;
	memset(Register,0,10*sizeof(int));
	memset(line,0,10*sizeof(int));
	for(j=0;j<lcount;j++)
	{
		
		
		if(strcmp(str[j],"mov")==0)
		{
		
			l=op[j][1];
			l=l-'0';
			
			Register[l]+=1;
			line[j]=Register[l];
			
		}
		
		else
		{
			
			l=op[j][1];
			m=op[j][4];
			n=op[j][7];
			l=l-'0';
			m=m-'0';
			n=n-'0';
			Register[l]=line[j]=(max(Register[m],Register[n])+1);
		
		}
		
	}
	
	for(j=0;j<lcount;j++)
	{
		fprintf(out,"%s %s\t%d\n",str[j],op[j],line[j]);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
		
			


