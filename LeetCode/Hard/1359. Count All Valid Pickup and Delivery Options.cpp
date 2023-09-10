class Solution {
public:
    int countOrders(int n) {
        unsigned long long cur=1;
        for(unsigned long long i=2;i<=n;i++){
            cur = (cur*i*(2*i-1))%((unsigned long long)1e9+7);
        }
        return cur;
    }
};