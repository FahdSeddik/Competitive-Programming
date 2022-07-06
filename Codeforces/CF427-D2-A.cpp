#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, res,o = 0, p = 0;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> res;
		o += res; 
		if (o <= -1) {
			p++;
			o = 0;
		}
	}
	cout << p;
}