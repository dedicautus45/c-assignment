#include <stdio.h>
#include<assert.h>
int lumen(int l ,int w)
{
return l*w;
}
int main ()
{
	
	int lum,watt,lump;
    


	printf("Enter the luminuous efficacy\n");
	scanf("%d",&lum);

        printf("Enter the number of lumens\n");
	scanf("%d",&watt);
assert(lumen(lum,watt)==54);
lump=lum*watt;

        printf("\n The luminous flux is" "%d",lump);
        

}
