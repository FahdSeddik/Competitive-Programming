#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi coords(n);
	for (int i = 0; i < n; i++)  cin >> coords[i];
	int ans = 1e9;
	for (int i = 0; i < n-1; i++) if (s[i] == 'R' && s[i + 1] == 'L')
		ans = min(ans, (coords[i + 1] - coords[i]) / 2);
	if (ans == 1e9) cout << -1;
	else cout << ans;
}
