class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> occ(26,vector<int>(26,0));
        int ans=0;
        for(auto str : words){
            if(occ[str[1]-'a'][str[0]-'a']){
                ans+=4;
                occ[str[1]-'a'][str[0]-'a']--;
            }else occ[str[0]-'a'][str[1]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(occ[i][i]){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};