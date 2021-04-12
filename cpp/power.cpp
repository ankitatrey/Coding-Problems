#include<iostream>
using namespace std;

//a recursive method for finding x^n in O(logn).
int power(int x, int n) {
	int temp;
	if(n == 0) return 1;

	temp = power(x, n/2);
	if(n%2 == 0) 
		return temp * temp;
	else return x * temp * temp;
}


int main(void) {
	cout << power(15, 5);
	return 0;
}