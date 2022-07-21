#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)

int main() {
	string s;
	cin >> s;
	int i = 0;
	while (i < s.size()) {
		if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
			s[i] = ' ';
			s[i+1] = ' ';
			s[i+2] = ' ';
		}
		else
			i++;
	}
	i = 0;
	while (i<s.size())
	{
		if (s[i] == ' ' && s[i + 1] == ' ') {
			s.erase(s.begin() + i, s.begin() + i+1);
		}
		else
			i++;
	}
	if (s[0] == ' ')
		s.erase(s.begin(), s.begin()+1);
	cout << s;
}