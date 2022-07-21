#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>


int main() {
	int t;
	cin >> t;
	vi a(t);
	for (int i = 0; i < t; i++)
	{
		cin >> a[i];
	}
	float sides;
	for (int i = 0; i < t; i++)
	{
		sides = 360.0 / (float)(180.0 - a[i]);
		if (sides == (int)sides)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}