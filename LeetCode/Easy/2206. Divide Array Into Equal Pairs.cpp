class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> s;
        for(auto v : nums)if(s.count(v))s.erase(v);
        else s.insert(v);
        return s.empty();
    }
};