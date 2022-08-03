#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define f(i,a,b) for(int i=a;i<b;i++)
#define lp(i,b) f(i,0,b)
#define rf(i,b,a) for(int i=b;i>=a;i--)
#define rlp(i,b) rf(i,b,0)
#define fll(i,a,b) for(long long i=a;i<b;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
#define vasort(v) sort(all(v))
#define vdsort(v) sort(allr(v))
#define read4(a,b,c,d) cin>>a>>b>>c>>d
#define sz(v) ((int)((v).size()))
typedef long long ll;
const double PI = acos(-1.0);
#pragma warning(disable:4996)
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65


int main()
{
	int n;
	cin >> n;
	vector<ll> v(n);
	fill(v, n);
	int m;
	cin >> m;
	vector<ll> dup(n+1);
	vector<ll> vac(n+1);
	partial_sum(all(v), vac.begin()+1);
	vasort(v);
	partial_sum(all(v), dup.begin()+1);
	vector<ll> ans;
	lp(i, m) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1) {
			ans.push_back(vac[r] - vac[l -1]);
		}
		else {
			ans.push_back(dup[r] - dup[l - 1]);
		}
	}
	lp(i, m)cout << ans[i] << "\n";
}

