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

const int N = 3e5 + 5;
struct pts { double x, y, r; }p[N];
double dist(int a, int b) { return sqrt((p[a].x - p[b].x) * (p[a].x - p[b].x) + (p[a].y - p[b].y) * (p[a].y - p[b].y)); }

int main() { 
	fastread();
	int n;
	cin >> n;
	lp(i, n)cin >> p[i].x >> p[i].y >> p[i].r;
	double ans = 0;
	lp(i, n) {
		int cnt = 0;
		lp(j, n) {
			if (i == j)continue;
			if (dist(i, j)<p[j].r && p[j].r>p[i].r)cnt++;
		}
		if (cnt % 2 == 0 && cnt)ans -= p[i].r * p[i].r;
		else ans += p[i].r * p[i].r;
	}
	cout << setprecision(10)<<fixed;
	cout<<ans* PI;
}