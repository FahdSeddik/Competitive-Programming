#include <bits/stdc++.h>
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	int max = n1 > n2 ? n1 : n2;
	int chances = 6 - max;
	if (chances == 0)cout << "1/6";
	else if (chances == 1)cout << "1/3";
	else if (chances == 2)cout << "1/2";
	else if (chances == 3)cout << "2/3";
	else if (chances == 4)cout << "5/6";
	else if (chances == 5)cout << "1/1";

}