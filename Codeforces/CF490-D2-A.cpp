#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int min3(int one, int two, int three) {
	if (one <= two && one <= three)
		return one;
	if (two <= one && two <= three)
		return two;
	if (three <= one && three <= two)
		return three;
}

int main() {
	int n;
	cin >> n;
	vi v(n);
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (v[i] == 1)
			one++;
		else if (v[i] == 2)
			two++;
		else if (v[i] == 3)
			three++;
	}
	if (!one || !two || !three) {
		cout << 0;
	}
	else {
		int min = min3(one, two, three);
		cout << min<<endl;
		int r = 0;
		auto lastone = v.begin();
		auto lasttwo= v.begin();
		auto lastthree= v.begin();
		for (int i = 0; i < min; i++)
		{
			lastone = find(lastone, v.end(), 1);
			lasttwo = find(lasttwo, v.end(), 2);
			lastthree = find(lastthree, v.end(), 3);
			cout <<  lastone- v.begin() + 1<<" ";
			cout << lasttwo - v.begin() + 1<<" ";
			cout << lastthree - v.begin() + 1<<"\n";
			lastone++;
			lasttwo++;
			lastthree++;
		}
		
		
	}

}