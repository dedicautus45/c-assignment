#include <stdio.h>
#include<assert.h>
int speed(int s)
{
int r;
r=0.2777778*s;
return r;
}
main ()
{
	int k,v;
        
printf("Enter the kilometer/hr \n");
	scanf("%d",&k);
assert(speed(k)==(int)10);
v=0.2777778*k;
	printf("%d",v);


}
