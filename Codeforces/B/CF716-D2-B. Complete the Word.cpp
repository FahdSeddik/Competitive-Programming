#include <bits/stdc++.h> 
using namespace std; 
#define vi vector<int> 
#define ANS(ans) cout << (ans? "YES":"NO") 
#define all(x) (x).begin(),(x).end() 
#define allr(x) (x).rbegin(),(x).rend() 
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i] 
#define fill_ll(vec,n) for(long long i=0;i<n;i++) cin>>vec[i] 
#define f(i,a,b) for(int i=a;i<b;i++) 
#define lp(i,b) f(i,0,b) 
#define rf(i,b,a) for(int i=b;i>=a;i--) 
#define rlp(i,b) rf(i,b,0) 
#define fll(i,a,b) for(long long i=a;i<b;i++) 
#define pr(i,j) cout<<i<<" "<<j 
#define pr3(i,j,k) pr(i,j)<<" "<<k 
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x)) 
#define vasort(v) sort(all(v)) 
#define vdsort(v) sort(allr(v)) 
#define sz(v) ((int)((v).size())) 
#define clr(v,d) memset(v,d,sizeof(v)) 
#define fastread() ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL) 
#define INF 0x3f3f3f3f 
#pragma warning(disable:4996) 
typedef long long ll; 
const double PI = acos(-1.0); 
int dx[8] = { 1,0,-1,0,-1,1,-1,1 }; 
int dy[8] = { 0,1,0,-1,-1,1,1,-1 }; 
template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x % y); } 

string s;

bool check(int i) {
	vi alph(26);
	f(j,i,i+26) {
		if (s[j] == '?') continue;
		alph[s[j] - 'A']++;
		if (alph[s[j] - 'A'] > 1) return 0;
	}
	return 1;
}

void fills(int i) {
	vi alph(26);
	for (int j = i; j < i + 26; j++) {
		if (s[j] == '?') continue;
		alph[s[j] - 'A']++;
	}
	queue<int> q;
	lp(i, 26)if (!alph[i])q.push(i);
	f(j,i,i+26) if (s[j] == '?')s[j] =(char)(q.front()+'A'), q.pop();
	lp(j,sz(s)) if (s[j] == '?') s[j] = 'A';
}

int main() { 
	fastread(); 
	cin >> s;
	if (sz(s) < 26) {
		cout << -1;
		return 0;
	}
	lp(i,sz(s)-25) {
		if (check(i)) {
			fills(i);
			cout << s;
			return 0;
		}
	}
	cout << -1;
}