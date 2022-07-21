#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int n = 0;
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (islower(s[i])) n++;
	}
	if (n >= (int)s.size() - n) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << s;
	}
	else {
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		cout << s;
	}
}