#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define lp(i,n) for(int i=0;i<n;i++)
#define pr(i,j) cout<<i<<" "<<j
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65



int main() {
	int n;
	cin >> n;
	int x = 0, y = 0, z = 0,t;
	lp(i, n) {
		cin >> t;
		x += t;
		cin >> t;
		y += t;
		cin >> t;
		z += t;
	}
	bool ans = !x && !y && !z;
	ANS(ans);
}
