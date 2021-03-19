#include<iostream>
using namespace std;

// Recursive program for tower of Hanoi

void towerOfHanoi(int n, char a, char b, char c) {
	if (n>=1) {
		towerOfHanoi(n-1, 'a', 'c','b');
		cout << "Move from " << a << " to " << c<<endl;
		towerOfHanoi(n-1, 'b','a', 'c');

	}
}

int main() {
	towerOfHanoi(4,'a','b','c');
	return 0;
}