#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main() {
	int n;
	cin >> n;
	string t;
	string team1, team2;
	int cnt1=0, cnt2=0;
	cin >> t;
	team1 = t;
	cnt1++;
	for (int i = 0; i < n-1; i++)
	{
		cin >> t;
		if (t != team1) {
			team2 = t;
			cnt2++;
		}
		else
			cnt1++;
	}
	if (cnt1 > cnt2)
		cout << team1;
	else
		cout << team2;
}