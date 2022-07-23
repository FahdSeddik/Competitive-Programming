#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO");
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65

int main() {
	vector<string> grid(4);
	for (int i = 0; i < 4; i++) cin >> grid[i];

	bool ans = false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[i][j] == grid[i][j + 1]) {
				if ((grid[i + 1][j] == grid[i][j]) || (grid[i][j] == grid[i + 1][j + 1]))
					ans = true;
			}
			else if (grid[i + 1][j] == grid[i][j]) {
				if (grid[i][j] == grid[i][j + 1] || grid[i][j] == grid[i + 1][j + 1])
					ans = true;
			}
			else if (grid[i][j + 1] == grid[i + 1][j + 1]) {
				if (grid[i][j + 1] == grid[i + 1][j] || grid[i][j + 1] == grid[i][j])
					ans = true;
			}
			if (ans)break;
		}
		if (ans)break;
	}
	ANS(ans);
}
