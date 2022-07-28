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
	string l1, l2, l3;
	getline(cin,l1);
	getline(cin,l2);
	getline(cin,l3);
	bool ans = true;
	int cnt = 0;
	lp(i, 0, l1.size())if (l1[i] == 'a' || l1[i] == 'e' || l1[i] == 'i' || l1[i] == 'o' || l1[i] == 'u')cnt++;
	if (cnt != 5)ans = false;
	cnt = 0;
	lp(i,0,l2.size())if (l2[i] == 'a' || l2[i] == 'e' || l2[i] == 'i' || l2[i] == 'o' || l2[i] == 'u')cnt++;
	if (cnt != 7)ans = false;
	cnt = 0;
	lp(i, 0, l3.size())if (l3[i] == 'a' || l3[i] == 'e' || l3[i] == 'i' || l3[i] == 'o' || l3[i] == 'u')cnt++;
	if (cnt != 5)ans = false;
	ANS(ans);
}

