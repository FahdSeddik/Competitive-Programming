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
#define read(a) cin>>a
#define read2(a,b) read(a)>>b
#define read3(a,b,c) read2(a,b)>>c
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
	vi a(n);
	fill(a, n);
	vi diff(n-1);
	lp(i, 0, n-1) {
		diff[i] = abs(a[i] - a[i + 1]);
	}
	int min = abs(diff[0] + diff[1]);
	int max = *max_element(all(diff));
	if (min < max) {
		min = max;
	}
	lp(i, 0, n - 2) {
		if (abs(diff[i] + diff[i + 1]) < min) {
			min = abs(diff[i] + diff[i + 1]);
			int max = *max_element(all(diff));
			if (min < max) {
				min = max;
			}
		}
	}
	cout << min;
}

