class Solution {
public:
    bool canTransform(string start, string end) {
        vector<pair<int,char>> s1,s2;
        for(int i=0;i<start.size();i++){
            if(start[i]!='X')s1.push_back({i,start[i]});
            if(end[i]!='X')s2.push_back({i,end[i]});
        }
        if(s1.size()!=s2.size())return false;
        for(int i=0;i<s1.size();i++){
            if(s1[i].second!=s2[i].second)return false;
            if(s1[i].second=='L'){
                if(s1[i].first<s2[i].first)return false;
            }else{
                if(s1[i].first>s2[i].first)return false;
            }
        }
        return true;
    }
};
