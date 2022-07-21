#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const double PI = 2.0 * acos(0.0);

int main() {
	int n, z, x, y;
	cin >> n >> z;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (x == z || x == 7 - z || y == z || y == 7 - z) {
			cout << "NO"; return 0;
		}
	}
	cout << "YES";
}