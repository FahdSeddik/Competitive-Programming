#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int cur = 0,res=0;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (abs((int)s[i] - 97 - cur) < 13)
			res += abs((int)s[i] - 97 - cur);
		else {
			res += 26 - abs((int)s[i] - 97 - cur);
		}
		cur = s[i] - 97;
	}
	cout << res;
}