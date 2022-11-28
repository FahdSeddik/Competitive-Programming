class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x<=9)return true;
        if(x%10==0)return false;
        long long rev=0,org=x;
        while(x){
            rev = rev*10 + x%10;
            x/=10;
        }
        return rev==org || rev/10==org;
    }
};