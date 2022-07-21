#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	if (n == 0 || n == 1 || n == 2)
		cout << 0;
	else {
		sort(v.begin(), v.end());
		int res = lower_bound(v.begin(), v.end(), v[n - 1]) - upper_bound(v.begin(), v.end(), v[0]);
		if (res < 0)cout << 0;
		else cout << res;
	}
}