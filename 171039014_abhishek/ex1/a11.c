#include<stdio.h>
#include<math.h>
#include<assert.h> 
/*int pow(int n,int m)
{
int i,p=1;
for(i=0;i<m;i++)
p*=n;
return p;
}*/
void bin_dec(long int num)   // Function Definition
{
long int rem,sum=0,power=0;
while(num>0)
 {
 rem = num%10;
 num = num/10;
 sum = sum + rem * pow(2,power);
 power++;
 }
printf("Decimal number : %ld",sum);
}

void main()
{
long int num;
printf("Enter the Binary number (0 and 1): ");
scanf("%ld",&num);
//assert(bin_dec(num));
bin_dec(num);
 
}
