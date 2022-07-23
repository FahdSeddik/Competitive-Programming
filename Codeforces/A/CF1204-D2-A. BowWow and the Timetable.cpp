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
	string s;
	cin >> s;
	int last1 = -1, cnt1s = 0;
	lp(i, s.size()) {
		if (s[i] == '1') {
			if (last1 == -1)
				last1 = i;
			cnt1s += 1;
		}
	}
	if (cnt1s == 0)
		cout << 0;
	else {
		last1 = s.size() - last1 - 1;
		if (last1 % 2 == 1)
			last1 += 1, cnt1s = 0;
		last1 = last1 / 2;
		if (cnt1s > 1)
			last1 += 1;
		cout << last1;
	}
	

}
