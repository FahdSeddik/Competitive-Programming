class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(),windowSize = 2 * k + 1;
        long long windowSum = 0;
        vector<int> result(n, -1);
        if (n<windowSize) return result;
        for (int i=0;i<n;i++) {
            windowSum += nums[i];
            if (i - windowSize >= 0) windowSum -= nums[i - windowSize]; 
            if (i >= windowSize - 1) result[i - k] = windowSum / windowSize;
        }
        return result;
    }
};