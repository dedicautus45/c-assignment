
#include <stdio.h>
int main()
{
    int a;
    float b;
    double c;
    char d;

          int sizeofa=sizeof(a);
          int sizeofb=sizeof(b);
          int sizeofc=sizeof(c);
          int sizeofd=sizeof(d);

    printf("Size of int: %d bytes\n",sizeofa);
    printf("Size of float: %d bytes\n",sizeofb);
    printf("Size of double: %d bytes\n",sizeofc);
    printf("Size of char: %d byte\n",sizeofd);
    return 0;
}
