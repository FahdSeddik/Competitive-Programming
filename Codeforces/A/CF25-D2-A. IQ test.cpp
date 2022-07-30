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
	int n;
	cin >> n;
	vi num(n);
	fill(num, n);
	int mod = num[0] % 2;
	int index = 0;
	lp(i, 1, n) {
		if (num[i] % 2 != mod) {
			if (i + 1 < n && num[i + 1] % 2 == num[i] % 2) {
				index = 0;
				break;
			}
			else if(i-1>0 && num[i-1]%2==num[i]%2) {
				index = 0;
				break;
			}
			else {
				index = i;
				break;
			}

		}
	}
	cout << index+1;
}

