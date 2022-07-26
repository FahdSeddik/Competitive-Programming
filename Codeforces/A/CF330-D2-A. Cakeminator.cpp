#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define lp(i,a,b) for(int i=a;i<b;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
#define vasort(v) sort(all(v))
#define vdsort(v) sort(allr(v))
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65



int main()
{
	int r, c;
	cin >> r >> c;
	vector<string> cake(r);
	fill(cake, r);
	int eaten=0;
	lp(i, 0, r) {
		int f = cake[i].find('S');
		if (f == -1) {
			lp(j, 0, c) {
				if (cake[i][j] == '.') {
					eaten++, cake[i][j] = '#';
				}
			}
		}
	}
	lp(i, 0, c) {
		bool any = false;
		lp(j, 0, r) {
			if (cake[j][i] == 'S') {
				any = true;
				break;
			}
		}
		if (any)continue;

		lp(j, 0, r) {
			if (cake[j][i] == '.')eaten++, cake[j][i] = '#';
		}
	}
	cout << eaten;
}

