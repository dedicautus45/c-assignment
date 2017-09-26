#include<stdio.h>
#include<assert.h>
/*int dec_to_bin(int dec)
{
 int r,q;int bin[100],i;
 quotient = dec;


    while(q!=0){

         bin[i++]= q % 2;

         q = q/ 2;
         r=bin[i];
    }
return r;
}*/
main(){

    int decimalNumber,remainder,quotient;

    int binaryNumber[100],i=1,j;

    printf("Enter any decimal number: ");

    scanf("%d",&decimalNumber);


    quotient = decimalNumber;

    //assert(dec_to_bin(decimalNumber));
    while(quotient!=0){

         binaryNumber[i++]= quotient % 2;

         quotient = quotient / 2;

    }


    printf("Equivalent binary value of decimal number %d: ",decimalNumber);

    for(j = i -1 ;j> 0;j--)

         printf("%d",binaryNumber[j]);


    return 0;

}
