#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const double PI = 2.0 * acos(0.0);

int main() {
	int n, k;
	cin >> n >> k;
	long long a;
	//num 0,.....,k
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a < pow(10, k)) continue;
		vi num(k+1,0);
		while (a!=0)
		{
			int mod = a % 10;
			if (mod<=k && !num[a % 10])num[mod] = 1;
			a = a / 10;
		}
		if (accumulate(num.begin(), num.end(), 0) == k + 1) count++;
	}
	cout << count;
}