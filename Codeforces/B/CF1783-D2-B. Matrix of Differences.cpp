#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i]
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
#define INF 0x3f3f3f3f
#pragma warning(disable:4996)
typedef long long ll;
const double PI = acos(-1.0);
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x % y); }



int main()
{
	fastread();
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		int j = 1, k = n * n;
		vector<int> a(k);
		for (int i = 0; i < n*n; i+=2,j++) {
			a[i] = j;
		}
		for (int i = 1; i < n * n; i += 2, k--) {
			a[i] = k;
		}
		bool t = false;
		for (int i = 0; i < n; i++,t=!t) {
			if (t)for (int w = n-1; w >= 0; w--)cout << a[i * n + w] << ' ';
			else for (int w = 0; w < n; w++)cout << a[i * n + w] << ' ';
			cout << '\n';
		}
	}
}