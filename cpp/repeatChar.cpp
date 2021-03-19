#include<iostream>
using namespace std;

// Given a string of even length, a character, and a integer n
// repeat the character in the middle of the string 'n' times.

string repeatChar(string s, char c, int n) {
	string result;

	for(int i=0; i <= (s.size()/2 - 1); i++) {
		result += s[i];
	}

	for(int i=0; i<n; i++) {
		result += c;
	}
	// cout << result << endl;
	
	for (int i = (s.size()/2); i < s.size(); ++i)
	{
		result += s[i];
	}
	return result;
}

int main() {
	string s;
	cin >> s;
	char c; cin >> c;
	int n; cin >> n;

	cout << repeatChar(s, c, n);
	
	return 0;
}