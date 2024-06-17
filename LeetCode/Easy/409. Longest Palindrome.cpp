class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        for(char c : s)freq[c]++;
        int ans=0,isOdd=0;
        for(auto& x : freq){
            if(x.second%2==0)ans+=x.second;
            else ans+=x.second-1,isOdd=1;
        }
        return ans+isOdd;
    }
};