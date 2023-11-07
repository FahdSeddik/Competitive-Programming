class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<pair<int,int>> monsters(n);
        for(int i=0;i<n;i++)monsters[i]={dist[i],speed[i]};
        sort(monsters.begin(),monsters.end(),[](auto& a,auto& b){
            return ((double)a.first/a.second)<((double)b.first/b.second);
        });
        int ans=1,time=1;
        for(int i=1;i<n;i++){
            if((double)monsters[i].first/monsters[i].second <=time)return ans;
            else ans++,time++;
        }
        return ans;
    }
};