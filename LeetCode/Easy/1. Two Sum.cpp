class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (visited.count(complement)) {
                return {visited[complement], i};
            }
            visited[nums[i]] = i;
        }
        return {};
    }
};