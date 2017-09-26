#include <stdio.h>

/* C Program to reverse a number */

long reverse(long);
 
int main()
{
   int n, r,t;
  printf("Enter the number:\n");
   scanf("%d", &n);

   t = reverse(n);
 
   printf("The reversed number is %d\n", t);
 
  
}
 
long reverse(long n)
{
    static long r = 0;
long rem;
 
   if (n == 0) 
     return 0;
  while (n!=0)

{
 rem=n%10;
r=r*10+rem;
n=n/10;
} 

return r;
}
