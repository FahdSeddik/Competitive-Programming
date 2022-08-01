#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "Yes":"No")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define rng(i,a,b) for(int i=a;i<b;i++)
#define lp(i,b) rng(i,0,b)
#define gnr(i,b,a) for(int i=b;i>=a;i--)
#define rlp(i,b) gnr(i,b,0)
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
	ll a, b, s;
	read3(a, b, s);
	a = abs(a);
	b = abs(b);
	s = abs(s);
	if (a + b == s) {
		ANS(true);
		return 0;
	}
	if (a + b > s) {
		ANS(false);
		return 0;
	}
	int moda = a % 2;
	int modb = b % 2;
	if ((moda + modb) % 2 == s % 2) {
		ANS(true);
	}
	else
	{
		ANS(false);
	}
}

