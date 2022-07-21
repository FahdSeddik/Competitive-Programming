#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, s = 0, d = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int c1 = 0, c2 = n - 1;
	bool ts = true;
	while (c1<=c2)
	{
		if (ts) {
			ts = false;
			if (v[c1] >= v[c2]) {
				s += v[c1];
				c1++;
			}
			else {
				s += v[c2];
				c2--;
			}
		}
		else {
			ts = true;
			if (v[c1] >= v[c2]) {
				d += v[c1];
				c1++;
			}
			else {
				d += v[c2];
				c2--;
			}
		}
	}
	cout << s << " " << d;
}