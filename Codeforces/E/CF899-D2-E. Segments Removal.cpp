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


const int maxn = 2e5 + 6;
int n, a[maxn];
set<pair<int, int>> s1, s2;

int main()
{
	fastread();
	cin >> n;
	int l, r;
	for (l = 1, r = 1; r <= n; r++) {
		cin >> a[r];
		if (a[r] != a[l]) {
			s1.insert({ l - r,l });
			s2.insert({ l,r - l });
			l = r;
		}
	}
	s1.insert({ l - r,l });
	s2.insert({ l,r - l });
	int cnt = 0;
	while (s1.size() > 1) {
		cnt++;
		pair<int, int> temp = *s1.begin();
		s1.erase(temp);
		int st = temp.second;
		int len = -temp.first;
		auto lpos = s2.lower_bound({ st,len });
		auto rpos = s2.upper_bound({ st,len });
		if (lpos == s2.begin() || rpos == s2.end()) {
			s2.erase({ st,len });
			continue;
		}
		lpos--;
		if (a[lpos->first] == a[rpos->first]) {
			int st1 = lpos->first, st2 = rpos->first;
			int len1 = lpos->second, len2 = rpos->second;
			s1.erase({ -len1,st1 });
			s1.erase({ -len2,st2 });
			s2.erase({ st1,len1 }), s2.erase({ st2,len2 });
			s1.insert({ -len1 - len2,st1 });
			s2.insert({ st1,len1 + len2 });
		}
		s2.erase({ st,len });
	}
	cnt++;
	cout << cnt;
}
