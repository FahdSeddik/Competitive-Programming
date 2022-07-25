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
	string original,lock;
	cin >> original >> lock;
	char c1,c2;
	ll moves = 0;
	lp(i, n) {
		c1 = original[i], c2 = lock[i];
		c1 -= 48, c2 -= 48;
		if (abs(c1 - c2) <= 5)moves += abs(c1 - c2);
		else {
			int max = c1 > c2 ? c1 : c2;
			moves += 9 - max + 1 + (c1 + c2) - max;
		}
	}
	cout << moves;
}
