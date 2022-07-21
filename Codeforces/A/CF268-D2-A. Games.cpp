#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> home(n), guest(n);
	for (int i = 0; i < n; i++)
	{
		cin >> home[i] >> guest[i];
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res+=count(guest.begin(), guest.end(), home[i]);
	}
	cout << res;
}