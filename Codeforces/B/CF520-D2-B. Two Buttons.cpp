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


int v[20001];

int main()
{
	fastread();
	
	int n, m; cin >> n >> m;
	if (n >= m) {
		cout << n - m;
		return 0;
	}
	queue<int> q;
	clr(v, -1);
	v[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == m) {
			cout << v[u];
			return 0;
		}
		int a = 2 * u;
		if (a <= 20000 && v[a] == -1) {
			v[a] = v[u] + 1;
			q.push(a);
		}
		int b = u - 1;
		if (b > 0 && v[b] == -1) {
			v[b] = v[u] + 1;
			q.push(b);
		}
	}
}
