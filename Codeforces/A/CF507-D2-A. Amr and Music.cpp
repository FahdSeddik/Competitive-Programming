#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define lp(i,a,b) for(int i=a;i<b;i++)
#define lp_ll(i,a,b) for(long long i=a;i<b;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
#define vasort(v) sort(all(v))
#define vdsort(v) sort(allr(v))
#define read3(a,b,c) cin>>a>>b>>c
#define read4(a,b,c,d) read3(a,b,c)>>d
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65



int main()
{
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> a(n);
	lp(i, 0, n)cin >> a[i].first, a[i].second = i + 1;
	vasort(a);
	vi indices;
	lp(i, 0, n) {
		if (k - a[i].first >= 0) {
			indices.push_back(a[i].second);
			k -= a[i].first;
		}
		else
			break;
	}
	if (!indices.size()) {
		cout << 0;
		return 0;
	}
	cout << indices.size() << endl;
	lp(i, 0, indices.size()) {
		cout << indices[i] << " ";
	}
}

