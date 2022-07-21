#include <iostream>
using namespace std;

int main() {
    int n,t,t2=0,res=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> t;
			t2 += t;
		}
		if (t2 >= 2) res++;
		t2 = 0;
	}
	cout << res;
}