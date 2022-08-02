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
const double PI = acos(-1.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65



bool g(pair<ll,int> a, pair<ll,int> b) {
	return a.second > b.second;
}

int main()
{
	ll n,m;
	cin >> n >> m;
	vector<pair<ll, int>> ab(m);
	fll(i, 0, m)cin >> ab[i].first >> ab[i].second;
	sort(all(ab), g);
	ll matches = 0;
	int i = 0;
	while(n>=0 && i<ab.size()){
		if (n - ab[i].first < 0) {
			matches += n * ab[i].second;
			break;
		}
		n -=ab[i].first;
		matches += ab[i].first * ab[i].second;
		i++;
	}
	cout << matches;
}

