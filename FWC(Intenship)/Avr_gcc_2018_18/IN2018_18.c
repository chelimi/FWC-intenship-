// Online C compiler to run C program online#include <stdio.h>
#include<stdio.h>
void IntegerToBinary(int num,char *binary){
        for(int i = 7; i>= 0; i--){
                binary[i] = (num % 2) + '0';
                num /= 2;
        }
        binary[8] = '\0';
       }
// MAIN PROGRAM
int main(void)
{
  float number = 27.625;
  int a = (int)number;
  float b = number - a;
  char binary_whole_part[9]="";
  char binary_fractional_part[9]="";
  IntegerToBinary(a,binary_whole_part);
  for(int i = 0; i < 8; i++){
    b *= 2;
    int bit = (int)b;
    binary_fractional_part[i] = bit + '0';
    b -= bit;
  }
  binary_fractional_part[8] = '\0';
  printf(binary_whole_part);
  printf(".");
  printf(binary_fractional_part);
  printf(".");
}
