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
	int n, k;
	cin >> n >> k;
	vi v(n);
	fill_rev(v, n);
	int number;
	if(v[n-k]==0)
		number = v.end()-upper_bound(v.begin(), v.end(), 0);
	else
		number = v.end() - upper_bound(v.begin(), v.end(),v[n-k]-1);
	cout << number;
}
