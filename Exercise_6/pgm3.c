/*********************************************************************************/
/**3. Modify the 2nd program by passing the file names as command line arguments.*/
/*********************************************************************************/
#include <stdio.h>
int main(int argc, char const *argv[])
{
	FILE*fpin,*fpout;
	char ch;
	
	fpin = fopen(argv[1],"r");
	fpout = fopen(argv[argc-1],"w");
	while(fscanf(fpin,"%c",&ch)!=EOF)
	{
		fprintf(fpout, "%c",ch );
	}
	return 0;
}