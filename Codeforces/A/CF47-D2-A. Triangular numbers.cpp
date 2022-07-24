#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ANS(ans) cout << (ans? "YES":"NO")
#define fill(vec,n) for(int i=0;i<n;i++) cin>>vec[i]
#define fill_rev(vec,n) for(int i=n-1;i>=0;i--) cin>>vec[i]
#define lp(i,n) for(int i=0;i<n;i++)
#define pr(i,j) cout<<i<<" "<<j
#define pr3(i,j,k) pr(i,j)<<" "<<k
typedef long long ll;
const double PI = 2.0 * acos(0.0);
// digits start 48 ascii
// lowercase letters 97 ascii
// uppercase 65


bool passed(int& value,int& target) {
    return (value * (value + 1) / 2) >= target;
}
bool correct(int& value, int& target) {
    return (value * (value + 1) / 2) == target;
}
bool bs(int n) {
    int l, r, mid;
    l = 1;
    r = n;
    while (l < r) {
        mid = (l + r) / 2;
        if (correct(mid,n))break;
        if (passed(mid,n))r = mid;
        else l = mid + 1;
    }
    return correct(mid, n);
}

int main()
{
    int n;
    cin >> n;
    if (n == 1 || n == 3 || n == 6)cout << "YES";
    else if (n == 2 || n == 4 || n == 7)cout << "NO";
    else ANS(bs(n));
}
