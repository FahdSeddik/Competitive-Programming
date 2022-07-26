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
	int grid[3][3]= { {0,0,0} ,{0,0,0},{0,0,0} };
	lp(i, 0, 3)
		lp(j, 0, 3)cin >> grid[i][j];
	bool result[3][3] = { {true,true,true} ,{true,true,true} ,{true,true,true} };
	lp(i, 0, 3) {
		lp(j, 0, 3) {
			if (grid[i][j] % 2 == 0)continue;
			result[i][j] = !result[i][j];
			if (i - 1 >= 0)result[i - 1][j] = !result[i - 1][j];
			if (i + 1 <= 2)result[i + 1][j] = !result[i + 1][j];
			if (j - 1 >= 0)result[i][j - 1] = !result[i][j - 1];
			if (j + 1 <= 2)result[i][j + 1] = !result[i][j + 1];
		}
	}
	lp(i, 0, 3) {
		lp(j, 0, 3) {
			cout << result[i][j];
		}
		cout << "\n";
	}
	
}

