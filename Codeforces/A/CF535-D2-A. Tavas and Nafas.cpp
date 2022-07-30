#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define lp(i,a,b) for(int i=a;i<b;i++)
#define lp_ll(i,a,b) for(long long i=a;i<b;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
#define vasort(v) sort(all(v))
#define vdsort(v) sort(allr(v))
#define read3(a,b,c) cin>>a>>b>>c
#define read4(a,b,c,d) read3(a,b,c)>>d
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65



int main()
{
	int s;
	cin >> s;
	int tens = s / 10;
	int units = s % 10;
	if (tens == 0 && units == 0) {
		cout << "zero";
		return 0;
	}
	if (tens == 1) {
		if (units == 0)
			cout << "ten";
		else if (units == 1)
			cout << "eleven";
		else if (units == 2)
			cout << "twelve";
		else if (units == 3)
			cout << "thirteen";
		else if (units == 4)
			cout << "fourteen";
		else if (units == 5)
			cout << "fifteen";
		else if (units == 6)
			cout << "sixteen";
		else if (units == 7)
			cout << "seventeen";
		else if (units == 8)
			cout << "eighteen";
		else if (units == 9)
			cout << "nineteen";
		return 0;
	}
	else if (tens == 2)
		cout << "twenty";
	else if (tens == 3)
		cout << "thirty";
	else if (tens == 4)
		cout << "forty";
	else if (tens == 5)
		cout << "fifty";
	else if (tens == 6)
		cout << "sixty";
	else if (tens == 7)
		cout << "seventy";
	else if (tens == 8)
		cout << "eighty";
	else if (tens == 9)
		cout << "ninety";
	if (tens != 0 && units!=0)cout << "-";
	if (units == 1)
		cout << "one";
	else if (units == 2)
		cout << "two";
	else if (units == 3)
		cout << "three";
	else if (units == 4)
		cout << "four";
	else if (units == 5)
		cout << "five";
	else if (units == 6)
		cout << "six";
	else if (units == 7)
		cout << "seven";
	else if (units == 8)
		cout << "eight";
	else if (units == 9)
		cout << "nine";
}

