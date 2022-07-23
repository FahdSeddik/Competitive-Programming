#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO");
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i];
#define lp(i,n) for(int i=0;i<n;i++)
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int main() {
	int n;
	cin >> n;
	bool ans = true;
	vi v(n);
	fill(v, n);
	sort(v.begin(), v.end());
	int index = 0;
	lp(i, n) {
		int c = 0;
		lp(j, n) {
			if (v[i] == v[j])
				c++;
		}
		if (n < 2 * c - 1) {
			ans = false;
			break;
		}
	}

	ANS(ans);
}
