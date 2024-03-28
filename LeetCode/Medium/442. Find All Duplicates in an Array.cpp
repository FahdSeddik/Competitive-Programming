class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int index = (nums[i]-1) % n;
            nums[index] += n;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) { 
            if (((nums[i]-1) / n) == 2)
                ans.push_back(i + 1);
        } 
        return ans;
    }
};