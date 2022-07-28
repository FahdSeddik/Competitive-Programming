#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define lp(i,a,b) for(int i=a;i<b;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
#define vasort(v) sort(all(v))
#define vdsort(v) sort(allr(v))
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65



int main()
{
	int n;
	cin >> n;
	vi a(n);
	fill(a, n);
	int mi = min_element(all(a)) - a.begin();
	int ma = max_element(all(a)) - a.begin();
	if (mi == n - 1 || mi == 0 || ma == n - 1 || ma == 0) {
		cout << n - 1;
		return 0;
	}
	if (mi > ma) {
		int p1 = (n - 1 - ma);
		int p2 = mi;
		cout << max(p1, p2);
		return 0;
	}
	else {
		int p1 = (n - 1 - mi);
		int p2 = ma;
		cout << max(p1, p2);
		return 0;
	}

	
}

