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
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65


int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> ne, po;
	int t1,t2;
	lp(i, n) {
		cin >> t1 >> t2;
		if (t1 < 0)
			ne.push_back(make_pair(t1,t2));
		else po.push_back(make_pair(t1,t2));
	}
	vdsort(ne);
	vasort(po);
	int nei = 0,poi=0;
	bool right = true;
	if (po.size() < ne.size())right = false;
	ll sum = 0;
	while (nei < ne.size() || poi < po.size()) {
		if (nei < ne.size() && poi < po.size()) {
			if (right)sum += po[poi].second, poi++;
			else sum += ne[nei].second, nei++;
			right = !right;
		}
		else if (nei < ne.size()) {
			sum += ne[nei].second;
			break;
		}
		else{
			sum += po[poi].second;
			break;
		}
	}
	cout << sum;
}

