#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i]
#define f(i,a,b) for(int i=a;i<b;i++)
#define lp(i,b) f(i,0,b)
#define rf(i,b,a) for(int i=b;i>=a;i--)
#define rlp(i,b) rf(i,b,0)
#define fll(i,a,b) for(long long i=a;i<b;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
#define vasort(v) sort(all(v))
#define vdsort(v) sort(allr(v))
#define sz(v) ((int)((v).size()))
#define clr(v,d) memset(v,d,sizeof(v))
#define fastread() std::ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
#define INF 0x3f3f3f3f
#pragma warning(disable:4996)
typedef long long ll;
const double PI = acos(-1.0);
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x % y); }

vector<string> str;
vector<string> revstr;
const int MAXN = 1e5+5;
ll dp[MAXN][2];
int cost[MAXN];
int n;

void getmin(int i) {
	if (i == n)return;
	if (min(dp[i - 1][0], dp[i - 1][1]) == LLONG_MAX)return;
	ll x= LLONG_MAX, y= LLONG_MAX, z= LLONG_MAX, w= LLONG_MAX;
	if (str[i] >= str[i - 1] && dp[i-1][0]!= LLONG_MAX) {
		x = dp[i - 1][0];
	}
	if (str[i] >= revstr[i - 1] && dp[i - 1][1] != LLONG_MAX) {
		y = dp[i - 1][1];
	}
	if (revstr[i] >= str[i - 1] && dp[i - 1][0] != LLONG_MAX) {
		z = dp[i - 1][0] + cost[i];
	}
	if (revstr[i] >= revstr[i - 1] && dp[i - 1][1] != LLONG_MAX) {
		w = dp[i - 1][1] + cost[i];
	}
	dp[i][0] = min(x, y);
	dp[i][1] = min(z, w);
	getmin(i + 1);
}


int main()
{
	fastread();
	clr(dp, LLONG_MAX);
	cin >> n;
	str = vector<string>(n);
	revstr = vector<string>(n);
	lp(i, n)cin >> cost[i];
	fill(str, n);
	lp(i, n)revstr[i] = string(str[i]),reverse(all(revstr[i]));
	dp[0][0] = 0;
	dp[0][1] = cost[0];
	getmin(1);
	ll ans = min(dp[n - 1][0], dp[n - 1][1]);
	if (ans == LLONG_MAX)cout << -1;
	else cout << ans;
}
