#include<iostream>
#include<string.h>
using namespace std;

void swap(char *a, char *b) {
	char *temp = a;
	a = b;
	b = temp;
}

void perm(string s, int l, int h) {
	if(l == h) {
		int f = s[0]-'0';
		int l = s[h-1]-'0';
		// cout << f << " " << l << " " << s<<endl;
		if(f==1 && l == 1){ // number of permutations of s which starts and ends with 1.
			cout << s << endl;
		}
	}
	else {
		for(int i=l; i<h; i++){
			swap(s[l], s[i]);
			perm(s, l+1, h);
			swap(s[l], s[i]);
		}
	}

}

int main() {
	string s;  cin >> s;
	perm(s, 0, s.length());
	return 0;
}