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
	//rats,women and children, men,captain;
	vector<string> rats, wc, men, captain;
	string name,role;
	lp(i, 0, n) {
		cin >> name >> role;
		if (role == "rat") {
			rats.push_back(name);
		}
		else if (role == "woman" || role == "child") {
			wc.push_back(name);
		}
		else if (role == "man") {
			men.push_back(name);
		}
		else
			captain.push_back(name);
	}
	for (auto t : rats)cout << t << endl;
	for (auto t : wc)cout << t << endl;
	for (auto t : men)cout << t << endl;
	for (auto t : captain)cout << t << endl;
}

