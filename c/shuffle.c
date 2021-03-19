#include <stdio.h>  
#include<stdlib.h>

void swap(int *x, int *y){
   int temp = *x;
   *x = *y;
   *y = temp;
}

void main(int argc, char *argv[] )  {  
  if (argc == 2){
     int num = atoi(argv[1]);

     int arr_length = 2*num + 1;
     int arr[arr_length];

     int j = -num;
     int i = 0;
     
     while(j <= num && i < arr_length){
        
           arr[i] = j;
           j++; i++;
      }
      
     for(int i = 0; i < arr_length; ++i){
        printf("%d  ", arr[i]);
     }
     printf("\n");
     
     for(int i=0 ; i < arr_length; ++i){
        j = rand() % (num + i);
        swap(&arr[i], &arr[j]);
     } 
     for(int i = 0; i < arr_length; ++i){
        printf("%d  ", arr[i]);
     }
     printf("\n");
  }
  else{
     printf("less number of arguments.\n");
  }

}
