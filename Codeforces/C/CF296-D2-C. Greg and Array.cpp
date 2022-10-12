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
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x)) 
#define vasort(v) sort(all(v)) 
#define vdsort(v) sort(allr(v)) 
#define sz(v) ((int)((v).size())) 
#define clr(v,d) memset(v,d,sizeof(v)) 
#define fastread() ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL) 
#define INF 0x3f3f3f3f 
#pragma warning(disable:4996) 
typedef long long ll; 
const double PI = acos(-1.0); 
int dx[8] = { 1,0,-1,0,-1,1,-1,1 }; 
int dy[8] = { 0,1,0,-1,-1,1,1,-1 }; 
template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x % y); } 

const int MAXN = 1e5 + 2;
ll a[MAXN], lrd[MAXN][3];
ll x[MAXN],fin[MAXN];

int main() { 
	fastread();
	ll n, m, k;
	ll l, r;
	cin >> n >> m >> k;
	fill(a, n);
	lp(i, m)cin >> lrd[i][0] >> lrd[i][1] >> lrd[i][2];
	lp(i, k) {
		cin >> l >> r;
		l--;
		x[l]++, x[r]--;
	}
	f(i, 1, m)x[i] += x[i - 1];
	lp(i, m)lrd[i][2] *= x[i];
	lp(i, m)fin[lrd[i][0] - 1] += lrd[i][2], fin[lrd[i][1]] -= lrd[i][2];
	f(i, 1, n)fin[i] += fin[i - 1], a[i] += fin[i];
	a[0] += fin[0];
	lp(i, n)cout << a[i] << ' ';
}