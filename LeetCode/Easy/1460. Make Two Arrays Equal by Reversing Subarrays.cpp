class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int freq[1001]={0};
        for(const auto e : target)freq[e]++;
        for(const auto e : arr)if(!freq[e])return false;else freq[e]--;
        return true;
    }
};