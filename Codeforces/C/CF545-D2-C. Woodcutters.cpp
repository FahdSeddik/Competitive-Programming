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
#define fastread() std::ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const double PI = acos(-1.0);
#pragma warning(disable:4996)
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int main()
{
	fastread();
	int n;
	cin >> n;
	vector<pair<ll, ll>> xh(n);
	lp(i, n)cin >> xh[i].first >> xh[i].second;
	if (n == 1 || n==2) {
		cout << n;
		return 0;
	}
	ll cnt = 2;
	f(i, 1, n - 1) {
		if (xh[i].first - xh[i - 1].first > xh[i].second) {
			cnt++;
		}
		else if (xh[i + 1].first - xh[i].first > xh[i].second) {
			cnt++;
			xh[i].first += xh[i].second;
		}
	}
	cout << cnt;
}
