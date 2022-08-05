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
#define fastread() std::ios_base::sync_with_stdio(false)
typedef long long ll;
const double PI = acos(-1.0);
#pragma warning(disable:4996)
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

vi ans;
int diff(char c,char wanted) {
	return abs(c - wanted);
}

void solve() {
	int n, m; cin >> n >> m;
	vector<string> s(n);
	fill(s, n);
	int min = 0;
	lp(k, m) {
		min += diff(s[0][k], s[1][k]);
	}
	lp(i, n) {
		lp(j, n) if(i!=j){
			int sum = 0;
			lp(k, m) {
				sum += diff(s[i][k], s[j][k]);
			}
			if (sum < min)min = sum;
		}
	}
	ans.push_back( min);

}
int main()
{
	fastread();
	int t; cin >> t;
	while (t--) {
		solve();
	}
	lp(i, sz(ans))cout << ans[i] << "\n";
}
