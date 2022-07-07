#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int res = 1;

	for (int j = 0; j < s2.size(); j++)
	{
		if (s1[res-1] == s2[j]) {
			res++;
		}
	}
	cout << res;
}