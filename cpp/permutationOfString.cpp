#include<iostream>
// #include<cstring>
using namespace std;

void perm(string s, int k) {
	static int a[3] {0};
	static string result[3];
	int i;

	if (s[k] == '\0') {
		// result[k] = '\0';
		//printf("%s\n", result);
		cout << result << endl;
	}

	else {
		for (i=0; s[i] != '\0'; i++) {
			if (a[i] == 0) {
				result[k] += s[i];
				a[i] = 1;
				perm(s, k+1);
				a[i] = 0;
			}
		}
	}
}


int main() {
	string s = "abc";
	// int size = strlen(s);
	//perm(s, 0);
	cout<<s<<endl;
	string str[4];
	for(int i=0; i<4; i++) {
		str[i] += "a";
	} 
	cout<<str;

	return 0;
}