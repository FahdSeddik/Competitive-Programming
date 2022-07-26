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
	string o1,o2,pile;
	cin >> o1>>o2>>pile;
	vi alphabetreq(26),alphabetpile(26);
	lp(i, 0, o1.size()) {
		char c = o1[i] - 65;
		alphabetreq[c]++;
	}
	lp(i, 0, o2.size()) {
		char c = o2[i] - 65;
		alphabetreq[c]++;
	}
	lp(i, 0, pile.size()) {
		char c = pile[i] - 65;
		alphabetpile[c]++;
	}
	ANS(alphabetpile == alphabetreq);
}

