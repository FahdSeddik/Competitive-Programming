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
	int cntstand = 0;
	string s;
	cin >> s;
	lp(i,0, s.size()) {
		if (s[i] == 'X')cntstand++;
	}
	if (cntstand > n / 2) {
		//make sit
		cntstand -= n / 2;
		int minutes = cntstand;
		lp(i, 0, n) if(cntstand){
			if (s[i] == 'X') {
				s[i] = 'x';
				cntstand--;
			}
		}
		cout << minutes << endl << s;
	}
	else if(cntstand<n/2){
		//standup
		int minutes = n/2-cntstand;
		cntstand = minutes;
		lp(i, 0, n)if (cntstand) {
			if (s[i] == 'x') {
				s[i] = 'X';
				cntstand--;
			}
		}
		cout << minutes << endl << s;
	}
	else {
		cout << 0 << "\n" << s;
	}

}

