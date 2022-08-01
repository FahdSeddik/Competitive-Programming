#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define f(i,a,b) for(int i=a;i<b;i++)
#define lp(i,b) f(i,0,b)
#define rf(i,b,a) for(int i=b;i>=a;i--)
#define rlp(i,b) rf(i,b,0)
#define fll(i,a,b) for(long long i=a;i<b;i++)
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
	int n;
	cin >> n;
	vector<string> checker(n);
	fill(checker, n);
	lp(i, n) {
		lp(j, n) {
			int cnt = 0;
			if (i - 1 >= 0 && checker[i - 1][j] == 'o')cnt++;
			if (j - 1 >= 0 && checker[i][j - 1] == 'o')cnt++;
			if (i + 1 < n && checker[i + 1][j] == 'o')cnt++;
			if (j + 1 < n && checker[i][j + 1] == 'o')cnt++;
			if (cnt % 2 == 1) {
				ANS(false);
				return 0;
			}
		}
	}
	ANS(true);
}

