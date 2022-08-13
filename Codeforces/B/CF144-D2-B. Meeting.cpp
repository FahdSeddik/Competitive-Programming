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
#define sz(v) ((int)((v).size()))
#define clr(v,d) memset(v,d,sizeof(v))
#define fastread() std::ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const double PI = acos(-1.0);
#pragma warning(disable:4996)
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int xa, ya, xb, yb;
vector<pair<pair<int, int>,int>> rad;

bool isCovered(int i, int x, int y) {
	int xr = rad[i].first.first, yr = rad[i].first.second, rr = rad[i].second;
	return rr * rr >= (xr - x) * (xr - x) + (yr - y) * (yr - y);
}

int main()
{
	fastread();
	cin >> xa >> ya >> xb >> yb;
	if (xa > xb)swap(xa, xb);
	if (ya > yb)swap(ya, yb);
	int n;
	cin >> n;
	//radiators
	lp(i, n) {
		int x, y, r;
		cin >> x >> y >> r;
		rad.push_back({ {x,y},r });
	}
	vasort(rad);
	ll blankets = 0;
	f(x, xa, xb + 1) {
		int y = yb;
		bool covered = false;
		lp(i, n) {
			if (isCovered(i, x, y)) {
				covered = true;
				break;
			}
		}
		if (!covered)blankets++;
	}
	f(x, xa, xb + 1) {
		int y = ya;
		bool covered = false;
		lp(i, n) {
			if (isCovered(i, x, y)) {
				covered = true;
				break;
			}
		}
		if (!covered)blankets++;
	}
	f(y, ya+1, yb) {
		int x = xa;
		bool covered = false;
		lp(i, n) {
			if (isCovered(i, x, y)) {
				covered = true;
				break;
			}
		}
		if (!covered)blankets++;
	}
	f(y, ya+1, yb) {
		int x = xb;
		bool covered = false;
		lp(i, n) {
			if (isCovered(i, x, y)) {
				covered = true;
				break;
			}
		}
		if (!covered)blankets++;
	}
	cout << blankets;
}
