#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if (n % 2 != 0) {
		n = n + 1;
		cout << -n / 2;
	}
	else
		cout << n / 2;
}