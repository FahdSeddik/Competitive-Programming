#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i]
#define f(i,a,b) for(int i=a;i<b;i++)
#define lp(i,b) f(i,0,b)
#define rf(i,b,a) for(int i=b;i>=a;i--)
#define rlp(i,b) rf(i,b,0)
#define fll(i,a,b) for(long long i=a;i<b;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
#define vasort(v) sort(all(v))
#define vdsort(v) sort(allr(v))
#define sz(v) ((int)((v).size()))
#define clr(v,d) memset(v,d,sizeof(v))
#define fastread() std::ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
#define INF 0x3f3f3f3f
#pragma warning(disable:4996)
typedef long long ll;
const double PI = acos(-1.0);
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x % y); }



int main()
{
	fastread();
	string s;
	cin >> s;
	
	vector<int> ans(sz(s),0);
	int first = s.find('a');
	if (first == -1) { lp(i, sz(ans))cout << ans[i] << ' '; return 0; }
	bool finding = false;
	if (first < sz(s) - 1 && s[first + 1] == 'a')finding = true;
	else ans[first] = 1;
	f(i, first + 1, sz(s)-1) {
		if (s[i] == 'b' && s[i + 1] == 'a') {
			ans[i] = 1;
			finding = true;
		}
		else if (finding && s[i] == 'a') {
			if (s[i + 1] == 'b')ans[i] = 1, finding = false;
			else if (i + 1 == sz(s) - 1)ans[i + 1] = 1, finding = false;
		}
		if (finding && s[i + 1] == 'a' && i + 1 == sz(s) - 1)ans[i + 1] = 1;
	}
	lp(i, sz(ans))cout << ans[i] << ' ';
}
