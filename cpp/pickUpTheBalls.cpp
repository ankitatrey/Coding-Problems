#include<bits/stdc++.h>
using namespace std;

// Given a number of boxes containing variable number of balls.
// Iteratively pick up the balls unless there are no balls in any box.
// Pick up the balls from the box containing the minimum number of balls
// and pick up the same amount of balls from all other boxes. If the 
// box gets empty, throw away the box.

// finally print the number of boxes are left before each iteration until there are none left.
int main(void)
{
	int n; cin>>n;
	int arr[n];
	int min_element;

	for(int i=0; i<n; ++i) cin >> arr[i];

	sort(arr, arr+n);

	int presentBoxes = n;
	for(int i=0; i<n;) {
		int temp = 0;
		int j;

		min_element = arr[i];
		cout << presentBoxes<< endl;

		for(j=i; j<n; ++j) {
			if(arr[j] == min_element) 
				temp++;
			else break;
		}
		presentBoxes -= temp;
		i = j;
	}

	return 0;
}