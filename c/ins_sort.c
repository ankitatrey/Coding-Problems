#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n);
void insertion_sort(int arr[], int n);

int main(int argc, char *argv[]){
    if(argc == 2){
        int N = atoi(argv[1]);
        int arr[N];
        srand(time(0));

        for(int i = 0; i < N; i++){
            arr[i] = (rand() % (11 -99 + 1)) + 11;
        }
        printArray(arr, N);
        insertion_sort(arr, N);
        printArray(arr, N);
    }
    else
        printf("Usage: ./happy key\n");
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; ++i)
        printf("%d ",arr[i]);
    printf("\n\n");
}

void insertion_sort(int arr[], int n){
    int key ,i, j;
    for (i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;        
    }  
}