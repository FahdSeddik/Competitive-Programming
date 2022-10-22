class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=1;
        int past=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=past){
                past=nums[i];
                nums[index]=past;
                index++;
            }
        }
        return index;
    }
};