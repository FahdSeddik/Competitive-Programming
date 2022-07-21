#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>


int main() {
	int n,b,d;
	cin >> n >> b >> d;
	long sum = 0;
	long t;
	long out = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		if (t > b)
			continue;
		else {
			sum += t;
			if (sum > d) {
				++out;
				sum = 0;
			}
		}
	}
	cout <<out;

}