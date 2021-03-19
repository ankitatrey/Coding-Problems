#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void merge(int arr[], int f, int m, int l);
void merge_sort(int arr[], int f, int l);
void printArray(int arr[], int n);

int main(void){
    int arr[N];
    srand(time(0));

    for(int i = 0; i < N; i++){
        arr[i] = (rand() % (11 -99 + 1)) + 11;
    }
    printArray(arr, N);
    merge_sort(arr, 0, N-1);
    printArray(arr, N);
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; ++i)
        printf("%d ",arr[i]);
    printf("\n\n");
}

void merge_sort(int arr[], int f, int l){
    if (f < l){
        int mid = (f + l) / 2;
        merge_sort(arr, f, mid);
        merge_sort(arr, mid + 1, l);
        merge(arr, f, mid, l);
    }
}

void merge(int arr[], int f, int m, int l){
    int n1 = m - f + 1;
    int n2 = l - m;
    int temp1[n1];
    int temp2[n2];

    for (int i = 0; i < n1; i++)
    {
        temp1[i] = arr[f + i];
    }
    for (int i = 0; i < n2; i++)
    {
        temp2[i] = arr[m+ 1 + i];
    }
    int i = 0, j = 0, k = f;

    while(i < n1 && j < n2){
        if(temp1[i] <= temp2[j]){
            arr[k] = temp1[i];
            i++;
        }
        else{
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }
    while (j < n2)
    {
        arr[k] = temp2[j];
        j++;
        k++;
    }
    while (i < n1)
    {
        arr[k] = temp1[i];
        i++;
        k++;
    }

}
