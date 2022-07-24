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


ll sum(ll i) {
	return (i * (i + 1)) / 2;
}

ll sum(ll s, ll e) {
	if (s <= 1)
		return sum(e);
	return sum(e) - sum(s - 1);
}

ll splitters(ll k, ll n) {
	//simulate binary search with start and end
	ll st = 1, en = k;
	
	while (st < en) {
		ll md = (st + en) / 2;
		ll s = sum(md, k);

		if (s == n)
			return k - md + 1;

		if (s > n)
			st = md + 1;
		else
			en = md;
	}

	return k - st + 2;
}
 
int main() {
	ll n, k;
	cin >> n >> k;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	else if (n <= k) {
		cout << 1;
		return 0;
	}
	else {
		--k;
		--n;
		if (sum(k) < n)
			cout << -1;
		else
			cout << splitters(k, n);
	}
}
