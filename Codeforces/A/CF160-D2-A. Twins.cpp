#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
	int n;
	cin >> n;
	vi coins(n,0);
	int a;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
		sum += coins[i];
	}
	sort(coins.begin(), coins.end());
	int sum1 = 0;
	int c = 0;
	for (int i = n-1; i >= 0; i--)
	{
		if (sum1 > sum / 2)break;
		sum1 += coins[i];
		c++;
	}
	cout << c; 
}