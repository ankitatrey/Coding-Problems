#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc == 2){
        
        int n = atoi(argv[1]);
        int arr[2*n-1][2*n-1], k;

        for(int i=0; i < 2*n-1; i++){
            k = n;
            if (i < n){
                for(int j=0; j< 2*n-1; j++){
                    printf("%d ",k);
                    if (i > j)
                        k = k - 1;
                    if (i+j >= 2*n-2)
                        k = k + 1;
                }
            }
            if ( i >= n){
                for(int j=0; j < 2*n-1; j++){
                    printf("%d ", k);
                    if( i+j  < 2*n-2)
                        k = k - 1;
                    if( j >= i)
                        k = k + 1;
                }
            }
            printf("\n");
        }
        
    }
    else
        printf("Provide one integer argument.\n");
}