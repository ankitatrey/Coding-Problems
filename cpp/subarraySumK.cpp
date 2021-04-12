#include<bits/stdc++.h>
using namespace std;

// subarray sum equal to k problem in single traversal of an 
// array with hash map.
// Time Complexity - O(n)

int subarraySumK(int arr[], int n, int k) {
	if (n==0) return 0;

	unordered_map<int, int> mymap;
	int curr_sum = 0;
	int i = 0;
	int cnt = 0;

	while(i<n) {
		curr_sum += arr[i];
		if (curr_sum == k)
			cnt += 1;

		if(mymap.find(curr_sum-k)!=mymap.end())
			cnt += mymap[curr_sum-k];

		mymap[curr_sum] += 1;
		i += 1;
	}
	return cnt;

}

int main(void) {
	int n, k;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> k;

	cout << subarraySumK(arr, n, k);
	return 0;
}