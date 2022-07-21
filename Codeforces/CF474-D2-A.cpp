#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main() {
	string key = "qwertyuiopasdfghjkl;zxcvbnm,./";
	char shift;
	cin >> shift;
	string in;
	cin >> in;
	string res = "";
	int sh;
	if (shift == 'R')
		sh = -1;
	else
		sh = +1;
	int size = key.size();
	for (int i = 0; i < in.size(); i++)
	{
		int index=find(key.begin(), key.end(), in[i])-key.begin();
		res += key[(index+sh)%size];
	}
	cout << res;
}