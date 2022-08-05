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


bool g(pair<double, int>&a, pair<double, int>&b) {
	if (abs(a.first - b.first) < 1e-7)return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	fastread();
	double n, t1, t2, k;
	read4(n, t1, t2, k);
	vector<pair<double,double>> ab(n);
	lp(i, n)cin >> ab[i].first >> ab[i].second;
	vector<pair<double,int>> ans(n);
	lp(i, n) {
		double maxh = max(ab[i].first * t1 * (100-k) / 100 + ab[i].second * t2, ab[i].second * t1 * (100-k) / 100 + ab[i].first * t2);
		ans[i].first = maxh;
		ans[i].second = i + 1;
	}
	sort(all(ans),g);

	lp(i, n) {
		cout << setprecision(0) << ans[i].second << " ";
		cout << setprecision(2)<<fixed << ans[i].first << "\n";
	}
}
