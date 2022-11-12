class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())return false;
        vector<int> al1(26,0),al2(26,0);
        for(int i=0;i<s1.size();i++)al1[s1[i]-'a']++;
        for(int i=0;i<s2.size();i++){
            al2[s2[i]-'a']++;
            if(i-(int)s1.size()>=0){
                al2[s2[i-s1.size()]-'a']--;
            }
            if(al1==al2)return true;
        }
        return al1==al2;
    }
};