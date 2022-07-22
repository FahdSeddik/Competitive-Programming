#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int main() {
	
	string scale, L="", R="", Off="";
	cin >> scale;
	int pipe = scale.find('|');
	L = scale.substr(0, pipe);
	R = scale.substr(pipe + 1);
	cin >> Off;
	int i = 0;
	for (auto ch : Off)
	{
		if (L.size() <= R.size())L += ch;
		else R += ch;
	}
	cout << ((L.size() == R.size()) ? (L + '|' + R):"Impossible");
}
