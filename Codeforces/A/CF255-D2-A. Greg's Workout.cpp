#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define lp(i,n) for(int i=0;i<n;i++)
#define pr(i,j) cout<<i<<" "<<j
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65



int main()
{
	int n;
	cin >> n;
	int chest = 0, biceps = 0, back = 0;
	lp(i, n) {
		int t;
		cin >> t;
		if (i % 3 == 0)chest += t;
		else if (i % 3 == 1)biceps += t;
		else back += t;
	}
	if (chest >= biceps && chest >= back)
		cout << "chest";
	else if (biceps >= chest && biceps >= back)
		cout << "biceps";
	else cout << "back";
}