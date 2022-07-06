#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v(4);
	for (int i = 0; i < 4; i++)
	{
		cin >> v[i];
	}
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < (int)s.size(); i++)
	{
		res += v[(int)s[i] - 49];
	}
	cout << res;
}