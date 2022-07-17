#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main() {
	long long n;
	cin >> n;
	vector<long long> v;
	while (n!=0)
	{
		v.push_back(n);
		cin >> n;
	}
	bool res = false;
	for (int i = 0; i < v.size(); i++)
	{
		for (long long j = 1; j < sqrt(v[i]); j++)
		{
			if (v[i] % j == 0)res = !res;
		}
		if (!res)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}