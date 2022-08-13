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
	int n, k;
	cin >> n >> k;
	vi a(n),b(n);
	int t,ac=0,bc=0;
	lp(i, n) {
		cin >> t;
		if (t >= 0)a[ac++] = t;
		else b[bc++] = t;
	}
	int rem = k - bc;
	if(rem<=0){
		lp(i, k)b[i] *= -1;
	}
	else {
		lp(i, bc)b[i] *= -1;
		rem = rem % 2;
		if (rem && bc && ac) {
			if (b[bc - 1] <= a[0])b[bc - 1] *= -1;
			else a[0] *= -1;
		}
		else if(rem && bc)b[bc - 1] *= -1;
		else if (ac && rem)a[0] *= -1;
	}
	cout << accumulate(all(b), 0) + accumulate(all(a), 0);
}
