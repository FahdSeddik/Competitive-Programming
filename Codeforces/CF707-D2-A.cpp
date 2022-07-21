#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main() {
	int n, m;
	cin >> n >> m;
	char c;
	bool color = false;
	for (int i = 0; i < n*m; i++)
	{
		cin >> c;
		if (c == 'C' || c == 'M' || c == 'Y')
			color = true;
	}
	if (color)
		cout << "#Color";
	else
		cout << "#Black&White";
}