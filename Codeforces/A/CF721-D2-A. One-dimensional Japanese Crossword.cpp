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
	char c;
	vi ans;
	int cntB = 0;
	lp(i, n) {
		cin >> c;
		if (c == 'B')cntB++;
		else if (cntB) {
			ans.push_back(cntB);
			cntB = 0;
		}
	}
	if (cntB)ans.push_back(cntB);
	if (!ans.size())
		cout << 0;
	else {
		cout << ans.size() << endl;
		lp(i, ans.size())cout << ans[i] << " ";
	}

}