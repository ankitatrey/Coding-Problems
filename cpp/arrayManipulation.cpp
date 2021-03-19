#include<bits/stdc++.h>
using namespace std;

// Starting with a 1-indexed array of zeros and a list of operations,
// for each operation add a value to each the array element between two given indices, inclusive.
// Once all operations have been performed, return the maximum value in the array. 
int main(void) {
	//int q; cin >> q;
	int query[3][3] = {{1, 5,3}, {4, 8, 7}, {6, 9, 1}};

	int array[10] {0};

	for(int i=0; i<3; i++) {
		int u = query[i][0];
		int v = query[i][1];
		while(u<=v) {
			array[u] += query[i][2];
			u++;
		}
	}
	
	sort(array, array+10);
	
	cout<< array[9];
	return 0;
}

