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


bool isOverlap(pair<int, int>&a, pair<int, int>&b) {
	return !(a.first > b.second || a.second < b.first);
}


int main()
{
	fastread();
	int p, q, l, r;
	read4(p, q, l, r);
	vector<pair<int, int>> a(p);
	lp(i, p)cin >> a[i].first >> a[i].second;
	vasort(a);
	vector<pair<int, int>> c(q);
	lp(i, q)cin >> c[i].first >> c[i].second;

	ll cnt = 0;
	f(i, l, r + 1) {
		bool overlap = false;
		lp(j, q) {
			pair<int, int> newp = { c[j].first + i,c[j].second + i };
			lp(k, p) {
				if (isOverlap(newp, a[k])) {
					cnt++;
					overlap = true;
					break;
				}
			}
			if (overlap)break;
		}
	}
	cout << cnt;
}
