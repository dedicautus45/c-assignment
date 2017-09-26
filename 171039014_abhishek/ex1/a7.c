#include <stdio.h>
#include<assert.h>
double sumseries(float);
float main()
{

    float number;double sum;

    printf("\n Enter the value:  ");

    scanf("%f", &number);
    assert(sumseries(number)==(double)1.5);
    sum = sumseries(number);

    printf("\n Sum of the above series = %lf\n ", sum);

}
double sumseries(float m)
{
    double sum2 = 0, f = 1, i;
    for (i = 1; i <= m; i++)
    {
    f = f * i;
    sum2 = sum2 +(1 / f);
    }
    return(sum2);
}
