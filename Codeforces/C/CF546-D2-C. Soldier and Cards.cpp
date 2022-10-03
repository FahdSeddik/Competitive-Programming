#include <bits/stdc++.h>
#include <unordered_map>
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
	int n;
	cin >> n;
	int k1, k2;
	cin >> k1;
	deque<int> p1, p2;
	int t;
	lp(i, k1)cin >> t, p1.push_back(t);
	cin >> k2;
	lp(i, k2)cin >> t, p2.push_back(t);
	set<deque<int>> sp1,sp2;
	ll fights = 0;
	while (sz(p1) && sz(p2)) {
		int c1 = p1.front(); p1.pop_front();
		int c2 = p2.front(); p2.pop_front();
		if (c1 > c2) {
			p1.push_back(c2);
			p1.push_back(c1);
		}
		else {
			p2.push_back(c1);
			p2.push_back(c2);
		}
		fights++;
		if (sp1.count(p1) && sp2.count(p2)) {
			cout << -1;
			return 0;
		}
		sp1.insert(p1);
		sp2.insert(p2);
	}
	cout << fights << ' ';
	if (sz(p1))cout << 1;
	else cout << 2;
}
