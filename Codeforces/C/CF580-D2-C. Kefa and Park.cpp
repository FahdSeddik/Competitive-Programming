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

const int MAXN = 1e5 + 5;
int n, m;
bool cat[MAXN],vis[MAXN];
vector<vi> adj;
ll ans;


void dfsutil(int v,int cats) {
	vis[v] = true;
	if (cats > m)return;
	int visitedn = 0;
	for (auto u : adj[v]) {
		if (!vis[u]) {
			if (cat[u] == 0)dfsutil(u, 0);
			else dfsutil(u, cats + cat[u]);
			visitedn++;
		}
	}
	if (visitedn == 0)ans++;
}

void dfs() {
	int src = 1;
	vis[src] = true;
	int cats = cat[src];
	if (cats > m)return;
	for (auto v : adj[src]) {
		if (!vis[v]) {
			if (cat[v] == 0)dfsutil(v, 0);
			else dfsutil(v, cats + cat[v]);
		}
	}
}

int main() { 
	fastread();

	cin >> n >> m;
	lp(i, n)cin >> cat[i+1];
	adj = vector<vi>(n+1);
	lp(i, n - 1) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs();
	cout << ans;
}