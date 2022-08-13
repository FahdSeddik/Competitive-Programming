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



int main()
{
	fastread();
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	lp(i, n)cin >> a[i].first, a[i].second = i;
	if (n == 1) {
		cout << "1\n" << a[0].first << " " << 0;
		return 0;
	}
	vasort(a);
	vector<pair<int, int>> ans;
	int change = 0;
	lp(i,n-1) {
		if (a[i].first != a[i + 1].first) {
			if(change!=-1)
				ans.push_back({ a[i].first,change });
			change = 0;
			continue;
		}
		else if (!change) {
			change = a[i + 1].second - a[i].second;
			continue;
		}
		else if(a[i+1].second-a[i].second != change) {
			change = -1;
		}
	}
	if (a[n - 1].first != a[n - 2].first)ans.push_back({ a[n - 1].first,0 });
	else if (change != -1)ans.push_back({ a[n-1].first, change });
	
	cout << sz(ans)<<"\n";
	lp(i, sz(ans)) {
		pr(ans[i].first, ans[i].second) << "\n";
	}
}
