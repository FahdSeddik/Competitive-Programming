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


int c[505], par[100005], dis[600][600], ans[600][600], n, m, k;
map<int, int> mp;

int Find(int x) {
	return x == par[x] ? x : par[x] = Find(par[x]);
}

bool check() {
	int index = 1;
	f(i, 1, k + 1) {
		int x = Find(index++);
		f(j, 1, c[i]) {
			if (x != Find(index++)) return false;
		}
	}
	return true;
}

void dijkstra(int st) {
	int vis[600];
	clr(vis, 0);
	f(i, 1, k + 1)ans[st][i] = dis[st][i];
	ans[st][st] = 0;
	vis[st] = 1;
	f(i, 1, k) {
		int mn = INF, index = 1;
		f(j, 1, k + 1) {
			if (!vis[j] && ans[st][j] < mn)index = j, mn = ans[st][j];
		}
		vis[index] = 1;
		f(j, 1, k + 1)if (!vis[j])ans[st][j] = min(ans[st][j], ans[st][index] + dis[index][j]);
	}
	return;
}

int main()
{
	fastread();
	cin >> n >> m >> k;
	clr(dis, INF);
	lp(i, n)par[i+1] = i + 1;
	lp(i, k)cin >> c[i + 1];
	int index = 1;
	lp(i, k) {
		lp(j, c[i+1]) {
			mp[index++] = i + 1;
		}
	}
	lp(i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		if (!w) {
			int a = Find(u);
			int b = Find(v);
			par[a] = b;
			dis[mp[u]][mp[v]] = 0, dis[mp[v]][mp[u]] = 0;
		}
		else {
			dis[mp[u]][mp[v]] = min(dis[mp[u]][mp[v]], w);
			dis[mp[v]][mp[u]] = min(dis[mp[v]][mp[u]], w);
		}
	}
	if (!check()) {
		cout << "No";
		return 0;
	}
	clr(ans, INF);
	lp(i, k)dijkstra(i + 1);
	cout << "Yes\n";
	lp(i, k) {
		lp(j, k) {
			if (ans[i + 1][j + 1] == INF)cout << "-1 ";
			else cout << ans[i + 1][j + 1] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
