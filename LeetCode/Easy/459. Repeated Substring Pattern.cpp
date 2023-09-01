class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string current = "";
        for(int k=0;k<s.size()-1;k++){
            current+=s[k];
            if(s.size()%current.size()==0){
                bool match=true;
                int j=0;
                for(int i=0;i<s.size() && match;i++){
                    if(s[i]!=current[j])match=false;
                    j = (j+1)%current.size();
                }
                if(match)return true;
            }
        }
        return false;
    }
};