#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define f(i,a,b) for(int i=a;i<b;i++)
#define lp(i,b) f(i,0,b)
#define rf(i,b,a) for(int i=b;i>=a;i--)
#define rlp(i,b) rf(i,b,0)
#define fll(i,a,b) for(long long i=a;i<b;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
#define vasort(v) sort(all(v))
#define vdsort(v) sort(allr(v))
#define read4(a,b,c,d) cin>>a>>b>>c>>d
#define sz(v) ((int)((v).size()))
#define fastread() std::ios_base::sync_with_stdio(false)
typedef long long ll;
const double PI = acos(-1.0);
#pragma warning(disable:4996)
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65


set<pair<int, int>> pts;//10^5

int main()
{
	fastread();
	int x1, y1, x2, y2, n;
	read4(x1, y1, x2, y2) >> n;

	lp(i, n) {
		int r, a, b;
		cin >> r >> a >> b;
		f(j, a, b + 1) {
			pts.insert({ r,j });
		}
	}
	map<pair<int, int>, int> len;
	queue<pair<int, int>> q;
	pair<int, int> s = { x1,y1 };
	pair<int, int> cur;
	
	q.push(s), len[s] = 0;

	int dep = 0, size = 1;
	for (; !q.empty(); ++dep, size = q.size()) {
		while (size--) {
			cur = q.front(), q.pop();

			lp(i, 8) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				pair<int, int> newp = { nx,ny };

				if (pts.count(newp) == 0 || len.count(newp) != 0)
					continue;

				q.push(newp), len[newp] = dep + 1;

				if (newp.first == x2 && newp.second == y2) {
					cout << dep + 1;
					return 0;
				}
			}
		}
	}
	cout << -1;
}
