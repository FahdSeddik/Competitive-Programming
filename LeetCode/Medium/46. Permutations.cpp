class Solution {
public:
    vector<vector<int>>ans;
    void permutation(vector<int>&arr,int start=0){
        if(start==arr.size())ans.push_back(arr);

        for(int i=start;i<arr.size();i++){
              swap(arr[i],arr[start]);
              permutation(arr,start+1);
              swap(arr[i],arr[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>> ans;
        // sort(nums.begin(),nums.end());
        // ans.push_back(nums);
        // while(next_permutation(nums.begin(),nums.end()))ans.push_back(nums);
        permutation(nums);
        return ans;
    }
};