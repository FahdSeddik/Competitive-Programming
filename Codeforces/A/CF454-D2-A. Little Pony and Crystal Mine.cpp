#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define lp(i,n) for(int i=0;i<n;i++)
#define pr(i,j) cout<<i<<" "<<j
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65



int main()
{
	int n;
	cin >> n;
	int Ds = 1;
	lp(i, n/2+1) {
		string stars((n - Ds) / 2, '*');
		string D(Ds, 'D');
		cout << stars << D << stars<<"\n";
		Ds += 2;
	}
	Ds = n;
	lp(i, n / 2 ) {
		Ds -= 2;
		string stars((n - Ds) / 2, '*');
		string D(Ds, 'D');
		cout << stars << D << stars << "\n";
	}
}