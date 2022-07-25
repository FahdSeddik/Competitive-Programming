#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define lp(i,n) for(int i=0;i<n;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65



int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> cards(n);
	lp(i, n)cards[i].second = i + 1, cin >> cards[i].first;
	sort(cards.begin(), cards.end());
	lp(i, n/2)cout << cards[i].second << " " << cards[n - 1 - i].second<<"\n";

}
