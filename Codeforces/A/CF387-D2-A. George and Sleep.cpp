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
	string s, t;
	cin >> s >> t;
	int shr = (s[0] - 48) * 10 + (s[1] - 48);
	int smin = (s[3] - 48) * 10 + (s[4] - 48);
	int thr = (t[0] - 48) * 10 + (t[1] - 48);
	int tmin = (t[3] - 48) * 10 + (t[4] - 48);
	if (thr > shr)
		shr += 24;
	shr -= thr;
	if (tmin > smin) {
		smin += 60;
		if (shr - 1 < 0)
			shr = 23;
		else
			shr--;
	}
	smin -= tmin;
	if (shr < 10)
		cout << 0 << shr << ":";
	else
		cout << shr << ":";
	if (smin < 10)
		cout << 0 << smin;
	else
		cout << smin;


}

