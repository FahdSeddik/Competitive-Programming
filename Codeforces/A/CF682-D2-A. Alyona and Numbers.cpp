#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const double PI = 2.0 * acos(0.0);

int main() {
	long n, m;
	cin >> n >> m;
	vector<long long> mod1(5);
	vector<long long> mod2(5);
	for (long i = 1; i <= n; i++)
		mod1[i % 5]++;
	for (long i = 1; i <= m; i++)
		mod2[i % 5]++;
	cout << mod1[0] * mod2[0] + mod1[1] * mod2[4] + mod1[2] * mod2[3] + mod1[3] * mod2[2] + mod1[4] * mod2[1];
}