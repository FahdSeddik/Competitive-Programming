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
double a, b;
double r22(double p1, double p2, double r1) {
	return (r1 * r1 * p1 / p2) / (a / b + p1 / p2);
}

int main()
{
	fastread();
	int n; cin >> n;
	vector<double> x(n); fill(x, n);
	vdsort(x);
	int m; cin >> m;
	vector<double> y(m); fill(y, m);
	vdsort(y);
	int k; cin >> k;
	vector<double> z(k); fill(z, k);
	vasort(z);
	cin >> a >> b;
	double maxr22 = -1;
	lp(i, n) {
		lp(j, m) {
			lp(w, k) {
				double r2 = r22(y[j], z[w], x[i]);
				double mout = (x[i] * x[i] - r2) * y[j];
				double min = r2 * z[w];
				if (abs(mout / min - a / b)<1e-7) {
					if (r2 > maxr22)maxr22 = r2;
					else {
						cout << setprecision(6) << fixed;
						cout << sqrt(maxr22);
						return 0;
					}
				}
			}
		}
	}
	cout << setprecision(6) << fixed;
	cout << sqrt(maxr22);
}
