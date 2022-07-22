#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const double PI = 2.0 * acos(0.0);

int main() {
	int r1, r2, c1, c2, d1, d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	// i j
	// k z
	int a, b, c, d;
	bool found = false;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 9; k++)
			{
				for (int z = 1; z <= 9; z++)
				{
					if (i != j && i != k && i != z && j != z && j != k && k != z) {
						if ((i + j) == r1 && (k + z) == r2 && (i + k) == c1 && (j + z) == c2 && (i + z) == d1 && (j + k) == d2) {
							found = true;
							a = i, b = j, c = k, d = z;
							break;
						}
					}
				}
				if (found)break;
			}
			if (found)break;
		}
		if (found)break;
	}
	if (found) {
		cout << a << " " << b << "\n";
		cout << c << " " << d;
	}
	else
		cout << -1;

}