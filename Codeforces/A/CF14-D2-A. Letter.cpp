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
#define read3(a,b,c) cin>>a>>b>>c
#define read4(a,b,c,d) read3(a,b,c)>>d
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65



int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> paper(n);
	fill(paper, n);
	int scol = m-1, lcol = 0, srow = n-1, lrow = 0;
	lp(i, 0, n) {
		lp(j, 0, m) {
			if (paper[i][j] == '*') {
				if (i < srow)srow = i;
				if (i > lrow)lrow = i;
				if (j < scol)scol = j;
				if (j > lcol)lcol = j;
			}
		}
	}
	lp(i, srow, lrow + 1) {
		lp(j, scol, lcol + 1) {
			cout << paper[i][j];
		}
		cout << endl;
	}
}

