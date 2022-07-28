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
	vector<vi> car(n, vi(n));
	lp(i, 0, n)
		lp(j, 0, n)cin >> car[i][j];
	int cnt = 0;
	vi indices;
	lp(i, 0, n) {
		bool good = true;
		lp(j, 0, n) {
			if (car[i][j] == 1 || car[i][j] == 3) {
				good = false;
				break;
			}
			
		}
		if (good) {
			cnt++;
			indices.push_back(i+1);
		}
	}
	cout << cnt << endl;
	for (auto t : indices)cout << t << " ";
}

