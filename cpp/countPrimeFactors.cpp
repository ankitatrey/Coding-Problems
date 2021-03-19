#include<iostream>
using namespace std;

int isprime(int N) {
	int j=2; int s=0;
	while(j<=N){
		if(N%j == 0) s++;
		j++;
	}
	if(s==1) return 1;
	else return 0;
}

int isfactor(int dividend, int divisor) {
	if(dividend % divisor == 0) return 1;
	else return 0;
}

int main(void) {
	int n; 	cin >> n;
	int count = 0;

	for(int i = 2; i<=n; i++) {
		if (isfactor(n,i) && isprime(i)) 
			count++;
	}

	cout << "No. of prime factors of "<<n <<" is: " <<count;
	return 0;
}