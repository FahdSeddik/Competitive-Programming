class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int i=0,j=0,n1=word1.size(),n2=word2.size();
        string ans="";
        while(i<n1 && j<n2)ans+=word1[i++],ans+=word2[j++];
        while(i<n1)ans+=word1[i++];
        while(j<n2)ans+=word2[j++];
        return ans;
    }
};