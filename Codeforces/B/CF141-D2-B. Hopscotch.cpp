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


int main() { 
	fastread(); 
	int a, x, y; cin >> a >> x >> y;
	if (abs(x) >= a || y%a==0) { cout << -1; return 0; }
	int height = y / a; //on the y/a +1 square
	if (height == 0 || height == 1 ) { 
		if ((long double)abs(x) - (long double)a / 2.0 >= 0)cout << -1;  
		else cout << height + 1;
		return 0;
	}
	int mod = height % 2;
	if (mod == 1 && (long double)abs(x) - (long double)a / 2.0 >= 0) { cout << -1; return 0; }
	else if (!mod && x == 0) { cout << -1; return 0; }
	int square=-1;
	
	if (!mod) {
		square = height / 2 * 3;
		if (x > 0)square++;
	}
	else {
		square = height / 2 * 3 + 2;
	}
	cout << square;
}