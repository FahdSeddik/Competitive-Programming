class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int freq[26];
        memset(freq,0,sizeof(freq));
        for(auto& s : words)for(char c : s)freq[c-'a']++;
        for(int f : freq)if(f%words.size()!=0)return false;
        return true;
    }
};