#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define lp(i,n) for(int i=0;i<n;i++)
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
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << '\n' << 'C';
	}
	else {
		bool even = true;
		if (n % 2 == 1) {
			cout << (n * n / 2)+1<<'\n';
			lp(i, n) {
				lp(j, n) {
					if (even) {
						cout << 'C';
						even = !even;
					}
					else {
						cout << '.';
						even = !even;
					}
				}
				cout << '\n';
			}
			
		}
		else {
			cout << n * n / 2 << '\n';
			lp(i, n) {
				lp(j, n) {
					if (even) {
						cout << 'C';
						even = !even;
					}
					else {
						cout << '.';
						even = !even;
					}
				}
				even = !even;
				cout << '\n';
			}
		}
		
	}
}

