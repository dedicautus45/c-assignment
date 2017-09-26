#include <stdio.h>

/* C Program to find GCD and LCM of two number*/

int gcd(int, int);
int lcm(int);
 
int main (){
  int x, y, hcf;
  int lcm;
 
  printf("Enter two integers\n");
  scanf("%d%d", &x, &y);
 
  hcf = gcd(x,y);
  lcm = (x*y)/hcf;
 
  printf("Greatest common divisor of %d and %d = %d\n", x, y, hcf);
  printf("Least common multiple of %d and %d = %d\n", x, y, lcm);
 
 
}
 
int gcd(int x, int y) 
{
  

while (x!=y)
{
      if (x>y)

         {  x=x-y; }

      if (y>x)

            {y=y-x;}


}
return x;
}
