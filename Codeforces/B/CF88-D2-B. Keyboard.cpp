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
typedef long long ll;
const double PI = acos(-1.0);
#pragma warning(disable:4996)
int dirx[] = { 0,1,-1,0 };
int diry[] = { 1,0,0,-1 };
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

bool can[26];
int n, m, k, q, res = 0;
char key[31][31];
char text[1000000];
vector<pair<int, int>> posKey[26], shift;

int dist(int i, int j, int shr, int shc)
{
	return (i - shr) * (i - shr) + (j - shc) * (j - shc);
}

bool check(int i, int j)
{
	for (int w = 0; w < shift.size(); w++)
	{
		int dis = dist(i, j, shift[w].first, shift[w].second);
		if (dis <= k * k)
			return true;
	}
	return false;
}


int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)              // keyboard keys
		scanf("%s", key[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (key[i][j] == 'S')
				shift.push_back(make_pair(i, j)); // position of each key
			else
				posKey[key[i][j] - 'a'].push_back(make_pair(i, j));
		}
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < posKey[i].size() && !can[i]; j++)
		{                                                                         //check of each key if can press on it with one hand
			can[i] = can[i] | check(posKey[i][j].first, posKey[i][j].second);
		}
	scanf("%d%s", &q, text);
	for (int i = 0; i < q; i++)
	{
		if (islower(text[i]))
		{
			if (posKey[text[i] - 'a'].empty())
			{
				res = -1;
				break;
			}
		}
		else
		{
			text[i] = tolower(text[i]);

			if (shift.empty() || posKey[text[i] - 'a'].empty())
			{
				res = -1;
				break;

			}

			if (!can[text[i] - 'a'])
				++res;
		}
	}
	printf("%d", res);

	return 0;
}
