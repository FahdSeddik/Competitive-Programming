#include <iostream>
using namespace std;

int main() {
	int n, res, i;
	for (i = 0; i < 25; i++)
	{
		cin >> n;
		if (n == 1) { res = i; }
	}
	cout << abs(2 - res / 5) + abs(2 - res % 5);
}