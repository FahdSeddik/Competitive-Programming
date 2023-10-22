class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)return true;
        int l=1,r=num;
        while(l<r){
            long long mid = (r-l)/2+l,sq=mid*mid;
            if(sq==num)return true;
            else if(sq>num)r=mid;
            else l=mid+1;
        }
        return false;
    }
};