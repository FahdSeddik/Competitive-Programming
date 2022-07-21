#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main() {
	int n, k;
	cin >> n >> k;
	string res = "";
	int last = 0;
	for (int i = 0; i < n; i++)
	{
		res += (char)(last % k + 97);
		last++;
	}
	cout << res;
}