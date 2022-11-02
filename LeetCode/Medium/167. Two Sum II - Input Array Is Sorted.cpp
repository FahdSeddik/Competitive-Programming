class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=numbers.size()-1,j=0;j<numbers.size() && i>=0 && j<i;){
            int sum=numbers[j]+numbers[i];
            if(sum==target)return {j+1,i+1};
            if(sum<target)j++;
            if(sum>target)i--;
        }
        return {-1};
    }
};