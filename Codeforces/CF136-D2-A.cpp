#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main() {
	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cout << find(v.begin(), v.end(), i) - v.begin()+1 << " ";
	}

}