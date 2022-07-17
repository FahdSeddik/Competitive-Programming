#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>


int main() {
	vi v;
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == '+')
			continue;
		else {
			v.push_back(s[i]-48);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size()-1; i++)
	{
		cout << v[i] << "+";
	}
	cout << v[v.size() - 1];
}