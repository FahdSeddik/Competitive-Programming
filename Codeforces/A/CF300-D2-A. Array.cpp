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
#define read3(a,b,c) cin>>a>>b>>c
#define read4(a,b,c,d) read3(a,b,c)>>d
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65


int main()
{
	int n;
	cin >> n;
	vi po,ne,z;
	int t;
	lp(i, n) {
		cin >> t;
		if (t < 0)ne.push_back(t);
		else if (t > 0)po.push_back(t);
		else z.push_back(t);
	}
	if (po.size() == 0) {
		po.push_back(ne[ne.size() - 1]);
		po.push_back(ne[ne.size() - 2]);
		ne.resize(ne.size() - 2);
	}
	if (ne.size() % 2 == 0) {
		z.push_back(ne.back());
		ne.resize(ne.size() - 1);
	}
	cout << ne.size()<<" ";
	lp(i, ne.size())cout << ne[i] << " ";
	cout <<"\n" << po.size() << " ";
	lp(i, po.size())cout << po[i] << " ";
	cout <<"\n" << z.size() << " ";
	lp(i, z.size())cout << z[i] << " ";
}

