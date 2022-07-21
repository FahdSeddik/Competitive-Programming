#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
const double PI = 2.0 * acos(0.0);
int main() {
	double d, h, v, e,p,a,t;
	cin >> d >> h >> v >> e;
    p = (PI * e * d * d) / 4.0;
    a = (PI * h * d * d) / 4.0;
    if (p < v)
    {
        t = a / (v - p);
        cout << "YES\n";
        printf("%.10lf\n", t);
    }
    else
    {
        cout << "NO";
    }
}