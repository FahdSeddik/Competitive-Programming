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
int dirx[] = { 0,1,-1,0 };
int diry[] = { 1,0,0,-1 };
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int main()
{
	ll n, m, k, t,a,b;
	read4(n, m, k, t);
	vector<ll> x;
	lp(i, k) {
		cin >> a >> b;
		a--, b--;
		x.push_back(a * m + b);
	}
	vasort(x);
	lp(i, t) {
		cin >> a >> b;
		a--, b--;
		ll cur = a * m + b;
		auto it = lower_bound(all(x), cur);
		if (it != x.end() && *it == cur) {
			cout << "Waste\n";
			continue;
		}
		else {
			ll num = cur - (it - x.begin());
			num = num % 3;
			if (!num) {
				cout << "Carrots\n";
				continue;
			}
			if (num == 1) {
				cout << "Kiwis\n";
				continue;
			}
			cout << "Grapes\n";
		}
	}
	

}
