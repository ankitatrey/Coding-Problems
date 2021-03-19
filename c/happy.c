#include <stdio.h>
#include <stdlib.h>

int isHappyNumber(int n){
    int rem = 0, sum = 0;
    while (n != 0)
    {
        rem = n%10;
        sum = sum + (rem * rem);
        n /= 10;
    }
    return sum;
}

int main(int argc, char *argv[]){
    if(argc == 2){
        int result = atoi(argv[1]);
        while (result != 1 && result != 4){
            result = isHappyNumber(result);
        }
        if(result == 1)
            printf("Happy number.\n");
        else
            printf("Unhappy Number.\n");                  
    }
    else
        printf("Usage: ./happy key\n");
}