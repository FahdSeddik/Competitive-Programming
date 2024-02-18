class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors={1,n};
        int i;
        for(i=2;i*i<n;i++){
            if(n%i==0)factors.push_back(i),factors.push_back(n/i);
        }
        if(n%(i*i)==0)factors.push_back(i);
        sort(factors.begin(),factors.end());
        return factors.size()>=k ? factors[k-1]:-1;
    }
};