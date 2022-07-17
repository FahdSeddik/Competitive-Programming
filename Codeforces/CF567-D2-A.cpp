#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main() {
	long n;
	cin >> n;
	vector<long long> v(n);
	vector<long long> temp(n);
	for (long i = 0; i < n; i++)
	{
		cin >> v[i];
		temp[i]=v[i];
	}
	sort(temp.begin(), temp.end());
	for (long i = 0; i < n; i++)
	{
		auto low=lower_bound(temp.begin(), temp.end(), v[i]);
		long long max = temp[n - 1];
		long long min = temp[0];
		if (low == temp.begin()) {
			cout << abs(*(low + 1) - v[i])<<" "<<abs(max-v[i])<<endl;
			continue;
		}
		if (low == temp.end()-1) {
			cout << abs(*(low - 1) - v[i]) << " " << abs(min - v[i]) << endl;
			continue;
		}
		if (abs(*(low - 1) - v[i]) < abs(*(low + 1) - v[i]))
			cout << abs(*(low - 1) - v[i]);
		else
			cout << abs(*(low + 1) - v[i]);
		cout << " ";
		if (max - v[i] > v[i] - min)
			cout << abs(max - v[i]) << endl;
		else
			cout << abs(v[i] - min) << endl;
	}
}