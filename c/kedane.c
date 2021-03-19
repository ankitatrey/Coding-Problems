#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

//program for finding largest sum continuous subarray 

int main(int argc, char *argv[]){
    if(argc == 2){
        int n = atoi(argv[1]);

        int arr[n], ul = n, ll = -n;
        srand(time(0));
        for (int i=0; i < n; ++i){
            int ele = (rand() % (ul - ll +1)) + ll;
            arr[i] = ele;
        }

        //printing array
        for (int i=0; i < n; ++i){
            printf(" %d", arr[i]);
        }
        printf("\n");
        
        int max_sum = 0, i = 0, sum = 0;
        for(int i=0; i < n; i++)
        {
            sum += arr[i];
            if (sum < 0)
                sum = 0;
            if(sum > max_sum)
                max_sum = sum; 
        }
        printf(" largest sum subarray: %d\n", max_sum);
        
    }
    else{
        printf("provide one extra integer arguments\n");
    }
}