class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, unordered_map<int, vector<int>>> mp;
        for(const auto& meeting : meetings) {
            mp[meeting[2]][meeting[0]].push_back(meeting[1]);
            mp[meeting[2]][meeting[1]].push_back(meeting[0]);
        }
        vector<bool> knows(n);
        knows[0]=true,knows[firstPerson]=true;
        int cur = n-2;
        for(const auto& x : mp){
            unordered_set<int> isVis;
            queue<int> q;
            for(const auto& u : x.second)if(knows[u.first])q.push(u.first);
            int size = q.size();
            for(;!q.empty();size=q.size()){
                while(size--) {
                    int u = q.front();q.pop();
                    isVis.insert(u);
                    for(int v : x.second.at(u))if(!isVis.count(v)){
                        if(!knows[v])knows[v]=true,cur--;
                        isVis.insert(v);
                        q.push(v);
                    }
                }
            }
            if(!cur)break;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)if(knows[i])ans.push_back(i);
        return ans;
    }
};