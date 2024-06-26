class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int n=nums.size(),ans=0;
        for(int i=0;i<=n-k;i++){
            if(!q.empty() && q.front()==i)q.pop();
            int cur=q.size()%2==0 ? nums[i]:1-nums[i];
            if(cur==0)q.push(i+k),ans++;
            nums[i]=1;
        }
        for(int i=n-k+1;i<n;i++){
            if(!q.empty() && q.front()==i)q.pop();
            int cur=q.size()%2==0 ? nums[i]:1-nums[i];
            if(cur==0)return -1;
        }
        return ans;
    }
};