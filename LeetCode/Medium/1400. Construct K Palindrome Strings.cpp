class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        int arr[26]={0};
        for(const auto& c : s)arr[c-'a']++;
        int odd_letters=0;
        for(const auto& i : arr){
            if(i%2)odd_letters++;
        }
        return odd_letters<=k;
    }
};