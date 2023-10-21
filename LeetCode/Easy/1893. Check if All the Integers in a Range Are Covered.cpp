class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int line[52]={0};
        for(const auto& v : ranges)line[v[0]]++,line[v[1]+1]--;
        int cnt=0;
        for(int i=1;i<=50;i++){
            cnt+=line[i];
            if(i>=left && i<=right){
                if(cnt==0)return false;
            }
        }
        return true;
    }
};