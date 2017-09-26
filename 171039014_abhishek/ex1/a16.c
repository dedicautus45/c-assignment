#include <stdio.h>
#include <string.h>
 int match(char [], char []);
 
int main() {
  char a[130], b[7];
  int position,i,j;
 
  printf("Enter some text\n");
  //gets(a);
  for(i=0;i<=130;i++)
  scanf("%c",&a[i]);
  printf("Enter a string to find\n");
  //gets(b);
  for(j=0;j<=8;j++)
  scanf("%c",&b[j]);
  position = match(a, b);
 
  if(position != -1) {
    printf("Found at location %d\n", position + 1);
  }
  else {
    printf("Not found.\n");
  }
 
  return 0;
}
 
int match(char text[], char pattern[]) {
  int c, d, e, text_length, pattern_length, position = -1;
 
  text_length    = strlen(text);
  pattern_length = strlen(pattern);
 
  if (pattern_length > text_length) {
    return -1;
  }
 
  for (c = 0; c <= text_length - pattern_length; c++) {
    position = e = c;
 
    for (d = 0; d < pattern_length; d++) {
      if (pattern[d] == text[e]) {
        e++;
      }
      else {
        break;
      }
    }
    if (d == pattern_length) {
      return position;
    }
  }
 
  return -1;
}
