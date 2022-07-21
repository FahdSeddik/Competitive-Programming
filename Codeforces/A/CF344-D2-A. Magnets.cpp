#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,t,res=0,tb;
	cin >> n;
	if (n == 1)
		cout << 1;
	else {
		cin >> tb;
		for (int i = 0; i < n-1; i++)
		{
			cin >> t;
			if (tb != t)res++;
			tb = t;
		}
		cout << res+1;
	}
	
}