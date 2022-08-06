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
enum State {
	NA, C,G, CG
};
int n;
vector<State> a;
int mem[100][4];
State smem[100];
int minrest(int i, int rest, State prev) {
	if (i == n)
		return rest;
	int& ret = mem[i][prev];
	if (ret != -1)
		return ret;
	if (a[i] == NA ) {
		rest++;
		ret = rest;
		smem[i] = NA;
		return minrest(i + 1, rest, NA);
	}
	if (prev == NA) {
		smem[i] = a[i];
		return minrest(i + 1, rest, a[i]);
	}
	if (prev == CG) {
		if (i - 2 < 0) {
			smem[i] = a[i];
			return minrest(i + 1, rest, a[i]);
		}
		else {
			if (a[i] == CG) {
				smem[i] = a[i];
				return minrest(i + 1, rest, a[i]);
			}
			else if (a[i] == C && smem[i-2]==G) {
				rest++;
				ret = rest;
				smem[i] = NA;
				return minrest(i + 1, rest, NA);
			}
			else if (a[i] == G && smem[i - 2] == C) {
				rest++;
				ret = rest;
				smem[i] = NA;
				return minrest(i + 1, rest, NA);
			}
			else {
				smem[i] = a[i];
				return minrest(i + 1, rest, a[i]);
			}
		}
	}
	if (prev == C) {
		if (a[i] == CG) {
			smem[i] = G;
			return minrest(i + 1, rest, G);
		}
		else if (a[i] == C) {
			rest++;
			ret = rest;
			smem[i] = NA;
			return minrest(i + 1, rest, NA);
		}
		else{
			smem[i] = G;
			return minrest(i + 1, rest, G);
		}
	}
	if (a[i] == CG) {
		smem[i] = C;
		return minrest(i + 1, rest, C);
	}
	else if (a[i] == C) {
		smem[i] = C;
		return minrest(i + 1, rest, a[i]);
	}
	else {
		rest++;
		ret = rest;
		smem[i] = NA;
		return minrest(i + 1, rest, NA);
	}
}
int main()
{
	fastread();
	cin >> n;
	int t;
	lp(i, n)cin >> t, a.push_back((State)t);
	lp(i, 100)lp(j, 4)mem[i][j] = -1;
	if (a[0] == NA) {
		smem[0] = NA;
		cout << minrest(1, 1, NA);
	}
	else {
		smem[0] = a[0];
		cout << minrest(1, 0, a[0]);
	}
}
