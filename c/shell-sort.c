#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
 

// Shell sort helps making insertion sort faster by performing its 
// generic operations by considering one gap factor.

void shellSort(int arr[], int n) {
	int gap, i, j, temp;

	for(gap = n/2; gap >= 1; gap /= 2) {

		for(i=gap; i<n; i++) {
			temp = arr[i];
			j = i-gap;

			while(j>=0 && arr[j] > temp) {
				arr[j+gap] = arr[j];
				j = j-gap;
			}
			arr[j+gap] = temp;
		}
	}
}

int main(int argc, char *argv[]) {
	if(argc == 2){
		int n = atoi(argv[1]);
		int arr[n], i;
		int ul = 80, ll=2;
		srand(time(0));

		for(i=0; i< n; i++) {
			int ele = (rand() % (ul - ll + 1)) + 2;
			arr[i] = ele;
		}
		

		for(i=0; i<n; i++) 
			printf("%d ", arr[i]);
		printf("\n");

		shellSort(arr,n);

		for(i=0; i<n; i++) 
			printf("%d ", arr[i]);
		printf("\n");                        
    }
    else
        printf("Usage: ./shell-sort key\n");
    return 0;
}