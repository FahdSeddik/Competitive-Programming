#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string ans = "YES";
	//check if m is prime
	//check if m is the next prime
	
	for (int i = 2; i <= sqrt(m); i++)if (m % i == 0)
	{
		ans = "NO";
		break;
	}
	if (ans != "NO") {
		for (int i = n+1; i < m; i++)
		{
			bool hasfact = false;
			for (int j = 2; j <= sqrt(i); j++) if(i%j==0)
			{
				hasfact = true;
				break;
			}
			if (!hasfact)
				ans = "NO";
			if (ans == "NO")
				break;
		}
	}
	cout << ans;

}