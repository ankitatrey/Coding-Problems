#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isArmstrong(int num, int lengthOfDigit){
  int rem, sum = 0;
  int n = num;
  
  while (num != 0){
    rem = num % 10;
    sum += pow(rem, lengthOfDigit);
    printf("%d\n",num);
    num = num / 10;
  }
  int result = (sum == n) ? 1 : 0;
  return result;
}

int main(int argc, char *argv[]){
    if(argc == 2){
        int N = atoi(argv[1]);
        int u;
        int lengthOfDigit;

        for (int i = 10; i <= N; i++) {
          lengthOfDigit = 0;
          u=i;
          while(u != 0) {
            u /= 10;
            lengthOfDigit++;
          }
          if(isArmstrong(i,lengthOfDigit) == 1) printf("%d ",i);
          else continue;
        }
        printf("\n");
    }
    else
        printf("Usage: ./armstrong key\n");
}
