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
typedef long long ll;
const double PI = acos(-1.0);
#pragma warning(disable:4996)
int dirx[] = { 0,1,-1,0 };
int diry[] = { 1,0,0,-1 };
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65




int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	fill(a, n);
	int l = -1, r = -1;
	lp(i, n-1) {
		if (a[i] > a[i + 1] && l == -1) {
			l = i;
			f(j, i, n - 1) {
				if (a[j] < a[j + 1]) {
					r = j;
					break;
				}
			}
			if (r == -1) {
				if (l == 0) {
					cout << "yes\n";
					pr(l + 1, n);
					return 0;
				}
				else if(a[n-1]>a[l-1]){
					cout << "yes\n";
					pr(l + 1, n);
					return 0;
				}
				else {
					cout << "no";
					return 0;
				}
			}
			if (l == 0 && r == n - 1) {
				cout << "yes\n";
				pr(l + 1, r + 1);
				return 0;
			}
			else if (l == 0 && a[l] < a[r+1]) {
				f(k, r + 1, n - 1) {
					if (a[k] > a[k + 1]) {
						cout << "no";
						return 0;
					}
				}
				cout << "yes\n";
				pr(l + 1, r + 1);
				return 0;
			}
			else if (r == n - 1 && a[r] > a[l - 1]) {
				cout << "yes\n";
				pr(l + 1, r + 1);
				return 0;
			}else if (l > 0 && a[l - 1] < a[r] && r + 1 < n && a[r + 1] > a[l]) {
				f(k, r + 1, n - 1) {
					if (a[k] > a[k + 1]) {
						cout << "no";
						return 0;
					}
				}
				cout << "yes\n";
				pr(l + 1, r + 1);
				return 0;
			}
			else {
				cout << "no";
				return 0;
			}
		}
	}
	cout << "yes\n1 1";
}

