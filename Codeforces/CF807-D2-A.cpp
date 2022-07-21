#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main() {
	int n;
	int r1, r2;
	cin >> n;
	int prev;
	//0 rated, -1 unrated
	bool notequal = false;
	cin >> r1 >> r2;
	if (r1 != r2)
		notequal=true;
	prev = r1;
	bool maybe = true;
	for (int i = 0; i < n-1; i++)
	{
		cin >> r1 >> r2;
		if (r1 != r2)
			notequal = true;
		else if (prev < r1)
			maybe = false;
		prev = r1;
	}
	
	if (notequal)
		cout << "rated";
	else {
		if (maybe)
			cout << "maybe";
		else
			cout << "unrated";
	}
	
}