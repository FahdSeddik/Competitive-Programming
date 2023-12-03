class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26]={0},temp[26]={0},ans=0;
        for(auto c : chars)freq[c-'a']++;
        for(auto& x : words){
            for(auto c : x)temp[c-'a']++;
            bool f=true;
            for(int i=0;i<26 && f;i++)f&=freq[i]>=temp[i];
            if(f)ans+=x.size();
            memset(temp,0,sizeof(temp));
        }
        return ans;
    }
};