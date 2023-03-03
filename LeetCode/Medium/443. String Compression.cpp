class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        char lastc=chars[0];
        int cur = 1;
        for(int i=1;i<chars.size();i++){
            if(chars[i]!=lastc){
                if(cur==1){
                    s+=lastc;
                }else{
                    s+=lastc;
                    s+=to_string(cur);
                }
                cur=1;
                lastc=chars[i];
            }else cur++;
        }
        s+=lastc;
        if(cur!=1)s+=to_string(cur);
        chars = vector<char>(s.begin(),s.end());
        return s.size();
    }
};