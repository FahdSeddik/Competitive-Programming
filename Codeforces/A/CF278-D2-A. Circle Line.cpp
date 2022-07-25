#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define f(i,a,b) for(int i=a;i<b;i++)
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
	int n;
	cin >> n;
	vi d(n);
	fill(d, n);
	int s, t;
	cin >> s >> t;
	--s, --t;
	int mini = s > t ? t : s;
	int max = s + t - mini;
	s = mini, t = max;
	int between = accumulate(d.begin() + s, d.begin() + t, 0);
	int other = accumulate(d.begin(), d.begin() + s, 0) + accumulate(d.begin() + t, d.end(), 0);
	cout << min(between, other);
}

