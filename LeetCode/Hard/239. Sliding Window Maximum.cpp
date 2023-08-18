class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>  q;
        int i=0,j=0;
        vector<int> ans;
        while(i<nums.size()){
            while(!q.empty() && nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(j > q.front())q.pop_front();
            if(i+1>=k){
                ans.push_back(nums[q.front()]);
                j++;
            }
            i++;
        }
        return ans;
    }
};

/*
7 6 5 4 3 2 1

5 5 4 3 2 1
*/