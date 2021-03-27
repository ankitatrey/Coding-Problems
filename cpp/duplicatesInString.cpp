#include<iostream>
using namespace std;

int main() {
	string s;  cin >> s;
	int hash[26] {0};
	// cout<< s[0]-97 << endl;

	for(int i=0; s[i]!='\0'; ++i) {
		hash[s[i]-97]++;
	}

	for(int i=0; i<26; ++i) {
		if (hash[i] > 1) {
			printf("%c, count = %d \n", i+97, hash[i]);
		}
	}
	return 0;
}