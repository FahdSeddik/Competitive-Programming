#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m, a;
	cin >> n >> m >> a;
	long long x = m / a;
	long long y = n / a;
	if (m % a != 0)
		++x;
	if (n % a != 0)
		++y;
	cout << x * y;
}