class Solution {
public:
    int par[100'001];
    int find(int x){
        return x==par[x] ? x:par[x]=find(par[x]);
    }
    void dsu(int x, int y) {
        x = find(x), y = find(y);
        if(x!=y)par[y]=x;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size()==1)return true;
        iota(par, par + 100'001, 0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)return false;
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    dsu(nums[i],j);
                    dsu(nums[i],nums[i]/j);
                }
            }
        }
        int p = find(nums[0]);
        for(int v : nums)if(find(v)!=p)return false;
        return true;
    }
};