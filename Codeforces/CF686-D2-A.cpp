#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>


int main() {
	int n;
	long long x;
	char c;
	cin >> n >> x;
	long long cur = x;
	long long dist = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == '+') {
			cin >> x;
			cur += x;
		}
		else if(c=='-') {
			cin >> x;
			if (x > cur)
				dist++;
			else
				cur -= x;
		}
	}
	cout << cur << " " << dist;
}