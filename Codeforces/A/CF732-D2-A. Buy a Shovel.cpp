#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, r;
	cin >> p >> r;
	int res = 1;
	int pri=p;
	while ((pri % 10) - r != 0 && (pri %10) !=0) {
		res++;
		pri +=p;
	}
	cout << res;
}