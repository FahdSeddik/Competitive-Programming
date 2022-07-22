#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int main() {
	string s = "";
	char digit;
	cin >> digit;
	if ((digit - 48) > 4 && (digit - 48) != 9)
		s += to_string(9 - (digit - 48));
	else
		s += digit;
	while (cin>>digit)
	{
		if (digit - 48 > 4)
			s += to_string(9 - (digit - 48));
		else
			s += digit;
	}
	cout << s;
}