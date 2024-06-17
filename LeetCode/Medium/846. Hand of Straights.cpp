class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> m;
        for(int v : hand)m[v]++;
        queue<pair<int,int>> q;
        int i=0;
        int cnt=0;
        int last=-1;
        for(auto& [val, freq] : m) {
            if(!q.empty() && q.front().first==i)cnt-=q.front().second,q.pop();
            if(cnt==0)last=-1;
            if(last==-1)last=val;
            else if(last+1!=val)return false;
            if(freq-cnt!=0)q.push({i+groupSize,freq-cnt});
            if(freq-cnt<0)return false;
            cnt+=freq-cnt;
            last=val;
            if(cnt<0)return false;
            i++;
        }
        if(!q.empty() && q.front().first==i)cnt-=q.front().second,q.pop();
        return cnt==0;
    }
};