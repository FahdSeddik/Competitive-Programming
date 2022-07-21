#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
	vi alphabet(26);
	int n;
	cin >> n;
	int unique = 0;
	if (n < 26) {
		string s;
		cin >> s;
		cout << "NO";
	}
	else {
		char c;
		for (int i = 0; i < n; i++)
		{
			cin >> c;
			int index = (int)tolower(c) - 97;
			if (!alphabet[index]) {
				alphabet[index] = 1;
				unique++;
			}
		}
		if (unique == 26)
			cout << "YES";
		else
			cout << "NO";
	}
}