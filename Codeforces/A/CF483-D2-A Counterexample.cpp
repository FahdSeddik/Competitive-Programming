#include <bits/stdc++.h>
using namespace std;

bool isCoprime(long long x, long long y) {
	if (x == 0 || y==0 || x==y)
		return false;
	if (x == 1 || y == 1)
		return true;
	if (x < y)
		return isCoprime(x, y % x);
	else
		return isCoprime(y, x % y);
}

int main() {
	long long l, r;
	long long a=-1,b=-1,c=-1;
	cin >> l >> r;
	bool br = false;
	for (long long i = l; i <= r-2; i++)
	{
		for (long long j = i+1; j <= r-1; j++)if(isCoprime(i,j))
		{
			for (long long k = j+1; k <= r; k++)if(isCoprime(j,k) && !isCoprime(i,k))
			{
				a = i;
				b = j;
				c = k;
				br = true;
				break;
			}
			if (br)
				break;
		}
		if (br)
			break;
	}
	if (a == -1)
		cout << -1;
	else
		cout << a << " " << b << " " << c;
}