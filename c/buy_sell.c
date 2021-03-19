#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maximal_subarray(int *deltas, int n){
    // int max_sum = 0, i = 0, sum = 0;
    // int end = 0; 
    //     for(int i=0; i < n; i++)
    //     {
    //         sum += deltas[i];
    //         if (sum < 0)
    //             sum = 0;
    //         if(sum > max_sum)
    //             max_sum = sum; 
    //             end = i;
    //     }
    //     int start = end;
    //     while (start >= 0) {
 
    //     max_sum -= deltas[start];
 
    //     if (max_sum == 0)
    //         break;
 
    //     // Decrement the start 
    //     start--;
    // }
    // int max_sum_array[end-start];

    // for(int i = start; i<= end; i++)
    //     for(int j = 0; j < end-start; j++)
    //         max_sum_array[j] = deltas[i];
    
    // return max_sum_array;
    int current_sum = 0;
    int max = 0;
    for(int i=0; i<n; ++i) {
        current_sum += deltas[i];
        if(current_sum < 0) 
            current_sum = 0;
        if (current_sum > max)
            max = current_sum;
    }
    return max;
}

int stocks(int array[], int n){
    int deltas[n];
    deltas[0] = 0;
    for (int i=1; i < n; i++){
        deltas[i] = array[i] - array[i - 1];
    }
    for (int i=1; i < n; i++){
        printf("%d ",deltas[i]);;
    }
    printf("\n");
    int best = maximal_subarray(deltas, n);

    return best;
}


int main(int argc, char *argv[]){
    if(argc == 2){
        int n = atoi(argv[1]);
        int arr[n], ul = 500, ll = 50;
        srand(time(0));
        for (int i=0; i < n; ++i){
            int ele = (rand() % (ul - ll +1)) + ll;
            arr[i] = ele;
        }
        for (int i=1; i < n; i++){
           printf("%d ",arr[i]);;
        }
        printf("\n");

        int profit = stocks(arr, n);
        printf("%d ", profit);
        printf("\n");
    }
    else
    {
       printf("Usage: ./buy_sell length of array.\n");
    }
}