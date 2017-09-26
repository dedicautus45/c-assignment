#include<stdio.h>
char roman_Number[1000];
int i=0;
void prefix(char c1,char c2){
    roman_Number[i++] = c1;
    roman_Number[i++] = c2;
}
 
void suffix(char c,int n){
    int j;
    for(j=0;j<n;j++)
         roman_Number[i++] = c;
 
}
 
int main(){
 
    int j;
    long int number;
 
    printf("Enter the number you wish to convert to ROMAN Number: ");
    scanf("%ld",&number);
 
    if(number <= 0){
        printf("Invalid number");
        printf("Enter the number you wish to convert to ROMAN Number: ");
        scanf("%ld",&number);
 
         return 0;
    }
 
    while(number != 0){
 
         if(number >= 1000){
             suffix('M',number/1000);
             number = number - (number/1000) * 1000;
         }
         else if(number >=500){
             if(number < (500 + 4 * 100)){
                 suffix('D',number/500);
                 number = number - (number/500) * 500;
             }
             else{
                 prefix('C','M');
                 number = number - (1000-100);
             }
         }
         else if(number >=100){
             if(number < (100 + 3 * 100)){
                 suffix('C',number/100);
                 number = number - (number/100) * 100;
             }
             else{
                 prefix('L','D');
                 number = number - (500-100);
             }
         }
         else if(number >=50){
             if(number < (50 + 4 * 10)){
                 suffix('L',number/50);
                 number = number - (number/50) * 50;
             }
             else{
                 prefix('X','C');
                 number = number - (100-10);
             }
         }
         else if(number >=10){
             if(number < (10 + 3 * 10)){
                 suffix('X',number/10);
                 number = number - (number/10) * 10;
             }
             else{
                 prefix('X','L');
                 number = number - (50-10);
             }
         }
         else if(number >=5){
             if(number < (5 + 4 * 1)){
                 suffix('V',number/5);
                 number = number - (number/5) * 5;
             }
             else{
                 prefix('I','X');
                 number = number - (10-1);
             }
         }
         else if(number >=1){
             if(number < 4){
                 suffix('I',number/1);
                 number = number - (number/1) * 1;
             }
             else{
                 prefix('I','V');
                 number = number - (5-1);
             }
         }
    }
 
    printf("Equivalent Roman Numeral is");
    for(j=0;j<i;j++)
         printf("%c",roman_Number[j]);
    return 0;
 
}
