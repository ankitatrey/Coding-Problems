#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
 
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int arr[], int l, int h) {
	int pivot = arr[l];
	int i = l, j = h;
	do{

	 	do{ i++; } while(arr[i] <= pivot);
	 	do{ j--; } while(arr[j] > pivot);

	 	if(i < j) 
	 		swap(&arr[i], &arr[j]);
	}
	while(i<j);

	swap(&arr[j], &arr[l]);
	return j;

}

 void quickSort(int arr[], int l, int h) {
 	
 	if(l<h){
 		int j = partition(arr, l, h);
 		quickSort(arr, l, j);
 		quickSort(arr, j+1, h);
 	}
 }


int main(int argc, char *argv[]) {
	if(argc == 2){
		int n = atoi(argv[1]);
		int arr[n], i;
		int ul = 50, ll=8;
		srand(time(0));

		for(i=0; i< n; i++) {
			int ele = (rand() % (ul - ll + 1)) + 2;
			arr[i] = ele;
		}
		

		for(i=0; i<n; i++) 
			printf("%d ", arr[i]);
		printf("\n");

		quickSort(arr, 0, n);

		for(i=0; i<n; i++) 
			printf("%d ", arr[i]);
		printf("\n");                        
    }
    else
        printf("Usage: ./qu_sort key\n");
    return 0;
}