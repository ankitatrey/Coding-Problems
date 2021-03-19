#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMax(int arr[], int n) {
	int max = arr[0];
	for(int i=0; i<n; i++) {
		if(arr[i] > max) max = arr[i];
	}
	return max;

}

void countSort(int arr[], int n) {
	int max = findMax(arr, n);

	int *C, i;
	C = (int *)malloc(sizeof(int)*(max+1));
	for( i=0; i<max+1; i++) 
		C[i] = 0;

	for( i=0; i<n; i++) 
		C[arr[i]]++;

	int j=0;
	i = 0;
	while(j < max+1){
		if(C[j] > 0) {
			arr[i++] = j;
			C[j]--;
		}
		else
			j++;
	}
}

int main(int argc, char *argv[]) {
	if(argc == 2){
		int n = atoi(argv[1]);
		int arr[n], i;
		int ul = 80, ll=8;
		srand(time(0));

		for(i=0; i< n; i++) 		
			arr[i] = (rand() % (ul - ll + 1)) + 2;
			
		
		for(i=0; i<n; i++) 
			printf("%d ", arr[i]);
		printf("\n");

		countSort(arr, n);

		for(i=0; i<n; i++) 
			printf("%d ", arr[i]);
		printf("\n");                        
    }
    else
        printf("Usage: ./count_sort key\n");
    return 0;
}