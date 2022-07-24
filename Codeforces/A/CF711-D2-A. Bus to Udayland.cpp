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
	vector<string> bus(n);
	bool found = false;
	lp(i, n) {
		cin >> bus[i];
		if (found)continue;
		if (bus[i][0] == 'O' && bus[i][1] == 'O') {
			bus[i][0] = '+', bus[i][1] = '+';
			found = true;
		}
		else if (bus[i][3] == 'O' && bus[i][4] == 'O') {
			bus[i][3] = '+', bus[i][4] = '+';
			found = true;
		}
	}
	ANS(found)<<endl;
	if (found)
		lp(i, n)cout << bus[i] << endl;
}