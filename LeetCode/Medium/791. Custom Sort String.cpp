class Solution {
public:
    string customSortString(string order, string s) {
        int ord[26]={0};
        for(int i=0;i<order.size();i++)ord[order[i]-'a']=i;
        sort(s.begin(),s.end(),[&](char a, char b){
            return ord[a-'a']<ord[b-'a'];
        });
        return s;
    }
};