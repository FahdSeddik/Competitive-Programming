#include <bits/stdc++.h>
#include <unordered_map>
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
#define vasort(v) sort(all(v))
#define vdsort(v) sort(allr(v))
#define sz(v) ((int)((v).size()))
#define clr(v,d) memset(v,d,sizeof(v))
#define fastread() std::ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
#pragma warning(disable:4996)
typedef long long ll;
const double PI = acos(-1.0);
int dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };
template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x % y); }


#define N 105
int a, b, c, d, n;
int ter[26];
char table[N][N];
pair<int, int> dir;
pair<int, int> cur;
bool mov;
void next() {
	cur.first += dir.first, cur.second += dir.second;

	if (!mov && (cur.second == 0 || cur.second == a+c-1) && cur.first<min(b,d)) {
		dir.first = 1, dir.second = 0;
		mov = true;
	}
	else if (!mov && cur.first >= min(b, d)) {
		if (b >= d) {
			if (cur.second == 0 || cur.second == a - 1) {
				dir.first = 1, dir.second = 0;
				mov = true;
			}
		}
		else if (d >= b) {
			if (cur.second == a || cur.second == a + c - 1) {
				dir.first = 1, dir.second = 0;
				mov = true;
			}
		}
		
	}
	else if(mov) {
		if (b >= d && cur.first >= min(b, d)) {
			if (a == 1 && c!=1) {
				dir.first = 1, dir.second = 0;
				mov = false;
				return;
			}
		}
		else if (d >= b && cur.first >= min(b, d)) {
			if (c == 1 && a!=1) {
				dir.first = 1, dir.second = 0;
				mov = false;
				return;
			}
		}
		if (cur.second == 0 || (cur.second == a && a!=a+c-1 && c!=1))dir.first = 0, dir.second = 1;
		else if (cur.second == a + c - 1 || (cur.second == a - 1 && (a!=a+c-1 && c!=1)) || (cur.second==a-1 && c==1))dir.first = 0, dir.second = -1;
		mov = false;
	}

}

int main()
{
	fastread();
	cin >> a >> b >> c >> d >> n;
	for (int i = 0; i < n; i++)cin >> ter[i];
	clr(table, '.');
	
	cur = { 0,0 };
	dir = { 0,0 };
	if (d <= b && d % 2 == 0)cur = { 0,0 }, dir = {0,1};
	else if (d <= b && d % 2 == 1)cur = { 0,a + c - 1 }, dir = {0,-1};
	else if (d >= b && b % 2 == 1)cur = { 0,0 }, dir = { 0,1 };
	else if (d >= b && b % 2 == 0)cur = { 0,a + c - 1 }, dir = { 0,-1 };
	mov = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ter[i]; j++) {
			table[cur.first][cur.second] = (char)('a' + i);
			next();
		}
	}
	cout << "YES\n";
	for (int i = 0; i < max(b, d); i++) {
		for (int j = 0; j < a + c; j++) {
			cout << table[i][j];
		}
		cout << '\n';
	}

}
