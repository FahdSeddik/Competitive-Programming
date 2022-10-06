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
 
const int MAXN = 100000 + 10;
vector<int> G[MAXN];
int a[MAXN], b[MAXN];
int n, m, d[MAXN], f[MAXN];
 
bool check(int k) {
    for (int i = 0; i < n; ++i) G[i].clear();
    for (int i = 0; i < n; ++i) f[i] = d[i] = 0;
    for (int i = 0; i < k; ++i) {
        G[a[i]].push_back(b[i]);
        d[b[i]]++;
    }
    queue<int> Q;
    for (int i = 0; i < n; ++i) if (d[i] == 0) {
        Q.push(i); f[i] = 1;
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto& v : G[u]) {
            f[v] = max(f[v], f[u] + 1);
            if (--d[v] == 0) Q.push(v);
        }
    }
    return *max_element(f, f + n) == n;
}
 
int main()
{
	fastread();
    cin >> n >> m;
    lp(i, m) {
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }
    if (!check(m)) {
        cout << -1; return 0;
    }
    int l = 1, r = m;
    while (l < r) {
        int m = (l + r - 1) >> 1;
        if (check(m))r = m;
        else l = m + 1;
    }
    cout << l;
}