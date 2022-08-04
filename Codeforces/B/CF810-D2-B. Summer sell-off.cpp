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
typedef long long ll;
const double PI = acos(-1.0);
#pragma warning(disable:4996)
int dirx[] = { 0,1,-1,0 };
int diry[] = { 1,0,0,-1 };
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65


int main()
{
	int N, F;
	cin >> N >> F;
	vector<pair <ll, ll>> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i].first >> A[i].second;
	vector<pair <ll, ll>> diff(N);
	for (int i = 0; i < N; i++)
	{
		diff[i].first = min(A[i].second - A[i].first, A[i].first);
		if (diff[i].first < 0)
			diff[i].first = 0;
		diff[i].second = i;
	}
	sort(all(diff), greater<pair <ll,ll>>());
	for (int i = 0; i < F; i++)
		A[diff[i].second].first *= 2;
	ll ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += min(A[i].first, A[i].second);
	}
	cout << ans << endl;
	return 0;
}

