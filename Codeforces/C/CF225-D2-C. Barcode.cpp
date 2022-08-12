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
#define read4(a,b,c,d) cin>>a>>b>>c>>d
#define sz(v) ((int)((v).size()))
#define clr(v,d) memset(v,d,sizeof(v))
#define fastread() std::ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const double PI = acos(-1.0);
#pragma warning(disable:4996)
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65


int n, m, x, y;
int dotsCount[1000 + 9]; 
int memo[1000 + 9][1000 + 9][3]; //0 dots 1 hashes 2 nothing

int solve(int col, int wid, int last) {

	if (col == m) {
		if (wid<x || wid>y)
			return 1000 * 1000;
		return 0;
	}

	int& ans = memo[col][wid][last];

	if (ans != -1)
		return ans;

	int dots = 1000 * 1000;

	if (col == 0 || (last == 0 && wid + 1 <= y) || (last == 1 && wid >= x)) {
		dots = n - dotsCount[col] + solve(col + 1, (last == 0) ? wid + 1 : 1, 0);
	}
	
	int hashes = 1000 * 1000;
	if (col == 0 || (last == 1 && wid + 1 <= y) || (last == 0 && wid >= x)) {
		hashes = dotsCount[col] + solve(col + 1, (last == 1) ? wid + 1 : 1, 1);
	}

	ans = min(dots, hashes);

	return ans;
}


int main()
{
	fastread();
	read4(n, m, x, y);
	lp(i, n) {
		lp(j, m) {
			char c;
			cin >> c;
			if (c == '.')dotsCount[j]++;
		}
	}
	clr(memo, -1);
	cout << solve(0, 0, 2);
}
