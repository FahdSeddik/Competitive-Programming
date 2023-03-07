class Solution {
public:
    int gcd(long long a,long long b){
        if(!b)return a;
        return gcd(b,a%b);
    }
    long long lcm(long long& a,long long& b){
        return a*b/gcd(a,b);
    }
    long long nthMagicalNumber(long long n, long long a, long long b) {
        const int MOD = 1e9+7;
        long L = lcm(a, b), C = (L/a) + (L/b) - 1, k = (n-1) / C, ans = 0;
        for(int i = 1, j = 1, magicalNeeded = n - k*C; magicalNeeded; magicalNeeded--) 
            if(a*i < b*j) ans = a * i++;
            else ans = b * j++;

        return (k*L + ans) % MOD;
    }
};