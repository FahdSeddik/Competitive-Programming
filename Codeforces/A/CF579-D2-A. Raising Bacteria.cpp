#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO");
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i];
#define lp(i,n) for(int i=0;i<n;i++)
#define pr(i,j) cout<<i<<" "<<j;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int main() {
	long long x;
	cin >> x;
	int sol = 0;
	while (x > 0) {
		if (x % 2 == 1)
			sol += 1;
		x /= 2;
	}
	cout << sol;
}
