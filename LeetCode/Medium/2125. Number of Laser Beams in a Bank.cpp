class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0,last=-1;
        for(auto& s : bank){
            int cnt=0;
            for(char c : s)if(c=='1')cnt++;
            if(!cnt)continue;
            if(last==-1)last=cnt;
            else ans+=last*cnt,last=cnt;
        }
        return ans;
    }
};