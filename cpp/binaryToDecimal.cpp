#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int powerof2 = 1;
		long long int result = 0;
		for(int i=s.size()-1; i>=0; --i) {
			int binary_digit = s[i] - '0';
			result += (binary_digit*powerof2);
			powerof2 *= 2;
		}
		cout << result << endl;
	}
	return 0;
}