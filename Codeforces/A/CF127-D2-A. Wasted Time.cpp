#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

double Dist(int x1, int y1,int x2,int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int n, k;
	cin >> n >> k;
	vi x(n);
	vi y(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	double dist = 0;
	for (int i = 0; i < n-1; i++)
	{
		dist += Dist(x[i], y[i], x[i + 1], y[i + 1]);
	}
	cout << setprecision(9)<<fixed;
	cout << (dist/(double)50.0) * (double)k;
}