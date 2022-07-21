#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v(4);
	for (int i = 0; i < 4; i++)
	{
		cin >> v[i];
	}
	cout<<4-set<int>{ v.begin(), v.end() }.size();

}