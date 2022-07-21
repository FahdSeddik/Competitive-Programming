#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main() {
	int n;
	cin >> n;
	vi indices(n+1);
	int p, q;
	cin >> p;
	int a;
	for (int i = 0; i < p; i++)
	{
		cin >> a;
		indices[a] = 1;
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> a;
		indices[a] = 1;
	}
	int sum = accumulate(indices.begin(), indices.end(), 0);
	if (sum == n)
		cout << "I become the guy.";
	else
		cout << "Oh, my keyboard!";
}