#include <bits/stdc++.h>
using namespace std;

int main() {
	long n;
	cin >> n;
	if (n == 0)
		cout << 1;
	else {
		int units[] = { 8,4,2,6 };
		n = (n - 1) % 4;
		cout << units[n];
	}
}