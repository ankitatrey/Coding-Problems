
#include <stdio.h>
#include <stdlib.h>
// program to count the number of 2s as digit in all numbers from 0 to n.

int main(int argc, char *argv[]) {
	if(argc == 2) {
		int n = atoi(argv[1]);
		int num = n;
		int count = 0;
	    for(int i=1; i<=n; i++) {
	    	while(i > 0){
	    		if(n%10 == 2) 
	    			count ++;
	    		i /= 10; 
	    	};
	    }
	    printf("Occurances of 2 as a digit upto %d is: %d\n",num, count);

	}
	else{
		printf("Usage: ./occurancesOf2 key\n");
	}
}