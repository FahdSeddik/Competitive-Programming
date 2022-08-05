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
#define sz(v) ((int)((v).size()))
#define fastread() std::ios_base::sync_with_stdio(false)
typedef long long ll;
const double PI = acos(-1.0);
#pragma warning(disable:4996)
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int fact[] = { 1,1,2,6,24,120,720,5040,40320,362880,3628800 };
ll factorial(ll n) {
	if (n <= 0)return (ll)1;
	if (n <= 10)return (ll)fact[n];
	return n * factorial(n - 1);
}


int main()
{
	fastread();
	string s1, s2;
	cin >> s1 >> s2;
	int drazil = count(all(s1), '+') - count(all(s1), '-');
	int dreamon= count(all(s2), '+') - count(all(s2), '-');
	int ques = count(all(s2), '?');
	if (abs(drazil - dreamon) % 2 != ques%2 || abs(drazil - dreamon) > ques) {
		cout << setprecision(9) << fixed;
		cout << (double)0;
		return 0;
	}
	if (drazil - dreamon == 0 && !ques) {
		cout << setprecision(9) << fixed;
		cout << (double)1;
		return 0;
	}
	int plus = 0;
	int minus = 0;
	int needed = drazil - dreamon;
	while (needed || ques) {
		if (needed < 0) {
			int ind = s2.find_first_of('?');
			s2[ind] = '-';
			ques--;
			minus++;
		}
		else {
			int ind = s2.find_first_of('?');
			s2[ind] = '+';
			ques--;
			plus++;
		}
		dreamon = count(all(s2), '+') - count(all(s2), '-');
		needed = drazil - dreamon;
	}
	double ways = (double)factorial(plus + minus) / (fact[plus] * fact[minus]);
	double prob = ways / (double)(1 << plus + minus);
	cout << setprecision(9) << fixed;
	cout << (double)prob;
}
