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
#pragma warning(disable:4996)
typedef long long ll;
const double PI = acos(-1.0);
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x % y); }




int main()
{
	fastread();
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n+1);
	lp(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	int qu; cin >> qu;
	vi ans;
	lp(k, qu) {
		int u, v;
		cin >> u >> v;
		int reach= 0;
		
		vector<bool> visc(m+1, false);
		lp(i, sz(adj[u])) {
			int node = adj[u][i].first;
			int color = adj[u][i].second;
			if (visc[color])continue;
			queue<int> q;
			vector<bool> vis(n+1, false);
			q.push(node);
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				if (cur == v) {
					reach++;
					visc[color] = true;
					break;
				}
				if (vis[cur])continue;
				vis[cur] = true;
				lp(j, sz(adj[cur])) {
					if (adj[cur][j].second == color && adj[cur][j].first!=u && !vis[adj[cur][j].first]) {
						q.push(adj[cur][j].first);
					}
				}
			}
		}
		ans.push_back(reach);
	}
	lp(i, sz(ans))cout << ans[i] << "\n";
}
