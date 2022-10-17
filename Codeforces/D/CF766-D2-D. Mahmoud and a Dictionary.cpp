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

int n, m, q;
const int MAXN = 2e5 + 5;
unordered_map<string, int> w_idx;
int par[MAXN];
int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

int main() { 
	fastread();
	cin >> n >> m >> q;
	lp(i, n) {
		string w;
		cin >> w;
		w_idx[w] = i;
		par[i] = i;
		par[i + n] = i + n;
	}
	lp(i, m) {
		int t;
		string w1, w2;
		cin >> t >> w1 >> w2;
		int x1 = find(w_idx[w1]);
		int x2 = find(w_idx[w1]+n);
		int y1 = find(w_idx[w2]);
		int y2 = find(w_idx[w2]+n);
		if (t == 1) {
			if (x1==y2 || x2==y1) {
				cout << "NO\n";
				continue;
			}
			par[x1] = y1;
			par[x2] = y2;
		}
		else {
			if (x1==y1 || x2==y2) {
				cout << "NO\n";
				continue;
			}
			par[x1] = y2;
			par[x2] = y1;
		}
		cout << "YES\n";
	}
	lp(i, q) {
		string w1, w2;
		cin >> w1 >> w2;
		int x1 = find(w_idx[w1]);
		int x2 = find(w_idx[w1] + n);
		int y1 = find(w_idx[w2]);
		int y2 = find(w_idx[w2] + n);
		if (x1 == y1 || x2==y2)cout << "1\n";
		else if (x1==y2 || x2==y1)cout << "2\n";
		else cout << "3\n";
	}
}