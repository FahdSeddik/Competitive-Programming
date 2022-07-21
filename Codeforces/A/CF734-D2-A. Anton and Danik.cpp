#include <iostream>
using namespace std;

int main() {
    int n, a = 0;
    char k;
    cin >> n;
    while (cin.get(k)) if (k == 'A')a++;
    if (a > n - a) cout << "Anton";
    else if (a < n - a) cout << "Danik";
    else cout << "Friendship";
}