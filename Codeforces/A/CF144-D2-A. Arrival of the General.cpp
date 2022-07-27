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
	int n;
	cin >> n;
	vi sold(n);
	fill(sold, n);
	int mini = 0, maxi = 0, min = sold[0], max = sold[0],steps=0;
	lp(i, 1, n) {
		if (sold[i] <= min)min = sold[i], mini = i;
		if (sold[i] > max)max = sold[i], maxi = i;
	}
	if (maxi < mini) {
		lp(i, mini, n - 1) {
			int temp = sold[i];
			sold[i] = sold[i + 1];
			sold[i + 1] = temp;
			steps++;
		}
		lp(i, 1, n) {
			if (sold[i] > max)max = sold[i], maxi = i;
		}
		for (int i = maxi; i > 0; i--) {
			int temp = sold[i];
			sold[i] = sold[i - 1];
			sold[i - 1] = temp;
			steps++;
		}
	}
	else {
		for (int i = maxi; i > 0; i--) {
			int temp = sold[i];
			sold[i] = sold[i - 1];
			sold[i - 1] = temp;
			steps++;
		}
		lp(i, 1, n) {
			if (sold[i] <= min)min = sold[i], mini = i;
		}
		
		lp(i, mini, n - 1) {
			int temp = sold[i];
			sold[i] = sold[i + 1];
			sold[i + 1] = temp;
			steps++;
		}
	}
	cout << steps;
}

