#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const double PI = 2.0 * acos(0.0);

int main() {
	int n, k;
	cin >> n >> k;
	vi y(2 * n + 1);
	for (int i = 0; i < 2*n+1; i++)
	{
		cin >> y[i];
	}
	for (int i = 1; i < 2*n; i++)
	{
		if (k != 0 && (i-1) % 2 == 0 && y[i] - 1 > y[i - 1] && y[i] - 1 > y[i + 1]) {
			--k, --y[i];
		}
	}
	for (int i = 0; i < 2*n+1; i++)
	{
		cout << y[i] << " ";
	}
}