#include <stdio.h>
#include<assert.h>
double energy(float ,float );
void main ()
{
	float d,e;
        float s;
	printf("Enter the energy consumption \n");
	scanf("%f",&d); 
	printf("Enter the time in seconds:\n");
	scanf("%f",&s);
	assert(energy(d,s)==(float)0.03);
	e=d/(1000*s);
	printf("energy is %f",e);
}
double energy(float d,float s)
{
float r;
r=d/(1000*s);
return r;
}
