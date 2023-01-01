class Solution {
public:
    int longestBeautifulSubstring(string word) {
        unordered_map<char,int> vow;
        vow['a']=1,vow['e']=2,vow['i']=3,vow['o']=4,vow['u']=5;
        int longest=0;
        int cur=0;
        int index=0;
        for(int i=0;i<word.size();i++){
            if(cur>longest && index==5)longest=cur;
            if(vow[word[i]]==index)cur++;
            else if(vow[word[i]]==index+1)cur++,index++;
            else if(vow[word[i]]==1)cur=1,index=1;
            else cur=0,index=0;
        }
        if(index==5 && longest<cur)longest=cur;
        return longest;
    }
};