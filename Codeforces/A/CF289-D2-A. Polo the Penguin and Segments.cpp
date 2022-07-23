#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int main() {
	int n, k;
	cin >> n >> k;
	long long l, r;
	long long range = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> l >> r;
		range += r - l + 1;
	}
	long long mod = range % k;
	if (mod == 0)
		cout << 0;
	else {
		cout << k - mod;
	}
}
