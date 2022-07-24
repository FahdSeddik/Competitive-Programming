#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO");
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i];
#define lp(i,n) for(int i=0;i<n;i++)
#define pr(i,j) cout<<i<<" "<<j;
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65
ll n, k;

ll power(ll b, ll p) {
	ll ans = 1, i ;
	for (i = 1; i <= p; i++)ans *= b;
	return ans;
}

ll reached(ll v) {
	ll i, ans, p;
	ans = v;
	p = 1;
	while (v / power(k, p) && ans < n) {
		ans += v / power(k, p);
		p++;
	}
	return ans >= n;
}

ll bs() {
	ll l, r, mid;
	l = 1;
	r = n;
	while (l < r) {
		mid = (l + r) / 2;

		if (reached(mid)) r = mid;
		else l = mid + 1;
	}
	return r;
}

int main() {
	cin >> n >> k;
	cout << bs();
}
