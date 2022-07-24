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



int main() {
	int sum = 0,x1,x2,x3;
	cin >> x1 >> x2 >> x3;
	int middle;
	if ((x1 <= x2 && x1 >= x3) || (x1 >= x2 && x1 <= x3))
		middle = x1;
	else if ((x2 <= x1 && x2 >= x3) || (x2 >= x1 && x2 <= x3))
		middle = x2;
	else
		middle = x3;
	cout << abs(x1 - middle) + abs(x2 - middle) + abs(x3 - middle);
}
