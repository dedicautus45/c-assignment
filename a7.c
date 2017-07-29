#include <stdio.h>
#include<assert.h>
float sumseries(float);
float main()
{

    float number,sum;

    printf("\n Enter the value:  ");

    scanf("%f", &number);
    assert(sumseries(number)==(float)1.5);
    sum = sumseries(number);

    printf("\n Sum of the above series = %f\n ", sum);

}

 

float sumseries(float m)
{
    float sum2 = 0, f = 1, i;
    for (i = 1; i <= m; i++)
    {
    f = f * i;
    sum2 = sum2 +(i / f);
    }
    return(sum2);
}
