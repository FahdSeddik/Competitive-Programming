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


int main()
{
	fastread();
	
	int n, m;
	cin >> n >> m;
	vector<vi> ab(n+1);
	int t1, t2;
	lp(i, m) {
		cin >> t1 >> t2;
		ab[t1].push_back(t2);
		ab[t2].push_back(t1);
	}
	ll cnt = 0;
	bool found = false;
	f(j, 1, n + 1) {
		if (ab[j].size() == 1) {
			cnt++;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << 0;
		return 0;
	}
	
	while (found) {
		found = false;
		vector<bool> lastedit(n + 1, false);
		f(i, 1, n + 1) {
			if (ab[i].size() == 1 && !lastedit[i]) {
				vector<int>::iterator it = find(all(ab[ab[i][0]]), i);
				ab[ab[i][0]].erase(it);
				lastedit[ab[i][0]] = true;
				ab[i].clear();
			}
		}
		f(j, 1, n + 1) {
			if (ab[j].size() == 1) {
				cnt++;
				found = true;
				break;
			}
		}
	}
	cout << cnt;
}
