#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define f(i,a,b) for(int i=a;i<b;i++)
#define lp(i,b) f(i,0,b)
#define rf(i,b,a) for(int i=b;i>=a;i--)
#define rlp(i,b) rf(i,b,0)
#define fll(i,a,b) for(long long i=a;i<b;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
#define vasort(v) sort(all(v))
#define vdsort(v) sort(allr(v))
#define read4(a,b,c,d) cin>>a>>b>>c>>d
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

string add(vector<string>&r) {
	string res = "";
	string carry = "0";
	
	int j = 0;
	lp(i, r[r.size()-1].size()) {
		int add = 0;
		lp(k, r.size()) {
			if(j<r[k].size())
				add += r[k][j] - 48;
		}
		if (carry.size() != 1 || carry[0] != '0') {
			add += stoi(carry);
			carry = "0";
		}
		res += to_string(add % 10);
		add /= 10;
		if (add)carry = to_string(add + stoi(carry));
		j++;
	}
	
	reverse(all(res));
	return res;
}


string multiply(string & a, string & b) {
	vector<string> result;
	rlp(i, a.size()-1) {
		string carry = "0";
		string r="";
		lp(j,a.size()-1-i)r += '0';

		rlp(j, b.size()-1) {
			int mult = (a[i] - 48) * (b[j] - 48);
			if (carry[0] != '0' || carry.size()!=1) {
				mult= mult + stoi(carry);
				carry = "0";
			}
			r += to_string(mult % 10);
			mult /= 10;
			if (mult)carry = to_string(mult + stoi(carry));
		}
		if (carry.size() != 1 || carry[0] != '0') {
			r += carry;
		}
		result.push_back(r);
	}
	return add(result);
}

int main()
{
	string a, b;
	vector<string> ans;
	while (cin >> a >> b)ans.push_back(multiply(a, b));
	lp(i, ans.size())cout << ans[i] << "\n";
}

