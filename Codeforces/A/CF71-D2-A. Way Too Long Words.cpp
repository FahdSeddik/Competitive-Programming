#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>


int main() {
	int n;
	cin >> n;
	string s;
	string res="";
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s.size() > 10) {
			res += s[0] + to_string(s.size() - 2) + s[s.size() - 1];
		}
		else
			res += s;
		if(i!=n-1)
			res += "\n";
	}
	cout << res;
}