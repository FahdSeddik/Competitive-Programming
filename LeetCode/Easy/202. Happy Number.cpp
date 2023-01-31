class Solution {
    unordered_set<int> s;
public:
    bool isHappy(int n) {
        while(n!=1 && !s.count(n)){
            s.insert(n);
            int c = 0;
            while(n){
                int t = n%10;
                c+=t*t;
                n/=10;
            }
            n=c;
        }
        return n==1;
    }
};