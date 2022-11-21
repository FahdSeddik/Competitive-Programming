#define TREE_SIZE 20001
#define OFFSET_N 10001


class Solution {
    int tree[TREE_SIZE];
public:
    int sum(int k){
        int s=0;
        while(k > 0 ){
            s+=tree[k];
            k-=k&-k;
        }
        return s;
    }
    void add(int k){
        while(k<TREE_SIZE){
            tree[k]++;
            k+=k&-k;
        }
    }
    vector<int> countSmaller(const vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            ans[i] = sum(nums[i]+OFFSET_N -1);
            add(nums[i]+OFFSET_N);
        }
        return ans;
    }
};