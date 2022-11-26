class Solution 
{
public:
    int sumSubarrayMins(vector<int>& n) 
    {
        vector<long> sums(n.size(),0);
        stack<long> s;
        long j, res=0, mod = 1000000007;
        for (int i = 0; i < n.size(); ++i)
        {
            while (!s.empty() && n[s.top()] > n[i])
                s.pop();
            j = !s.empty() ? s.top() : -1;
            
            sums[i] = ((j>=0?sums[j]:0) + (i-j)*n[i]) % mod;
            s.push(i);
        }

        for (int i = 0; i < sums.size(); ++i)
            res = (res + sums[i]) % mod;
        return res;
    }
};