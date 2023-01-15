class Solution {
    vector<vector<int>> ans;
public:
    void Complete(vector<int>& candidates,vector<int>& curv,int target,int i=0){
        if(target==0){
            ans.push_back(curv);
            return;
        }
        if(i==candidates.size() || target<0)return;
        Complete(candidates,curv,target,i+1);
        curv.push_back(candidates[i]);
        Complete(candidates,curv,target-candidates[i],i);
        curv.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        Complete(candidates,temp,target);
        return ans;
    }
};