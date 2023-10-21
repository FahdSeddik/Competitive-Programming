class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> cnt(2*limit+2);
        for(int i=0;i<n/2;i++){
            int a = nums[i],b=nums[n-i-1];
            cnt[2]+=2;
            cnt[min(a,b)+1]--;
            cnt[a+b]--;
            cnt[a+b+1]++;
            cnt[max(a,b)+limit+1]++;
        }
        int ans=2*n,cur=0;
        for(int i=2;i<=2*limit;i++){
            cur+=cnt[i];
            ans=min(ans,cur);
        }
        return ans;
    }
};

/*
2 <= T < min(A, B) + 1, we need 2 operations to make both A, B smaller
min(A, B) + 1 <= T < A + B, we need 1 operation to make the larger one out of A and B smaller
T = A + B, we need 0 operation
A + B < T < max(A, B) + limit, we need 1 operation to make the smaller one out of A and B larger
max(A, B) + limit < T <= 2 * limit, we need 2 operation to make both A, B larger

*/