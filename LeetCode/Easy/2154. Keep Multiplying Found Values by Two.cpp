class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int found[1001]={0};
        for(auto i : nums)if(i%original==0)found[i/original]=1;
        for(int i=1;i<1001;i*=2){
            if(!found[i])return original;
            original*=2;
        }
        return original;
    }
};