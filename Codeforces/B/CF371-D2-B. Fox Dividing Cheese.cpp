#include <bits/stdc++.h>
#include <unordered_map>
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
#pragma warning(disable:4996)
typedef long long ll;
const double PI = acos(-1.0);
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x % y); }


int fact1[3], fact2[3];

int main()
{
	fastread();
	
	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0; return 0;
	}
	while (a) {
		if (!(a % 2))
			fact1[0]++, a /= 2;
		else if (!(a % 3))
			fact1[1]++, a /= 3;
		else if (!(a % 5))
			fact1[2]++, a /= 5;
		else break;
	}
	while (b) {
		if (!(b % 2))
			fact2[0]++, b /= 2;
		else if (!(b % 3))
			fact2[1]++, b /= 3;
		else if (!(b % 5))
			fact2[2]++, b /= 5;
		else break;
	}
	if (a != b)
		cout << -1;
	else cout << abs(fact1[0] - fact2[0]) + abs(fact1[1] - fact2[1]) + abs(fact1[2] - fact2[2]);


}
