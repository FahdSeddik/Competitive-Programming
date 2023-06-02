class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26]={0};
        for(auto c : magazine)freq[c-'a']++;
        for(auto c : ransomNote)freq[c-'a']--;
        for(auto i : freq)if(i<0)return false;
        return true;
    }
};