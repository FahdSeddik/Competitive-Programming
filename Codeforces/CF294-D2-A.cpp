#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> lines(n+2);
	lines[0] = 0;
	for (int  i = 1; i <= n; i++)
	{
		cin >> lines[i];
	}
	lines[n + 1] = 0;
	int m;
	cin >> m;
	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		lines[x - 1] += y - 1;
		lines[x + 1] += lines[x] - y;
		lines[x] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << lines[i] << endl;
	}
}