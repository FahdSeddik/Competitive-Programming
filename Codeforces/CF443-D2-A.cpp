#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

//alphabet ascii start from 97 lowercase
int main() {
	vi alphabet(26,0);
	char c;
	cin >> c;
	while (c != '}') {
		cin >> c;
		if (c != ',' && c != ' ' && c!='}') {
			if (alphabet[(int)c - 97]==0)
				alphabet[(int)c - 97]+=1;
		}
	}
	cout << accumulate(alphabet.begin(), alphabet.end(), 0);
}