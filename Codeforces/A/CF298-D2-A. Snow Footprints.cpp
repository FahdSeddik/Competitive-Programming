#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO");
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i];
#define lp(i,n) for(int i=0;i<n;i++)
#define pr(i,j) cout<<i<<" "<<j;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	int t = -1;
	int s;
	lp(i, n) {
		if (str[i] == 'R' && str[i + 1] == 'L') {
			t = i + 1;
			for (int j = i; j >=0 && str[j]=='R'; j--)
			{
				s = j + 1;
			}
			break;
		}
		else if (str[i] == 'R' && str[i + 1] == '.') {
			t = i + 2;
			for (int j = i; j >= 0 && str[j] == 'R'; j--)
			{
				s = j + 1;
			}
			break;
		}
		else if (str[i] == '.' && str[i+1] == 'L') {
			t = i + 1;
			for (int j = i+1; j < n && str[j]=='L'; j++)
			{
				s = j+1;
			}
			break;
		}

	}

	pr(s, t);
}
