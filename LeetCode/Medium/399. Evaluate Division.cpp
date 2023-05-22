class Solution {
public:
    double dfs(unordered_map<string,vector<pair<string,double>>>& mp,string src,string& dest,unordered_set<string>& vis,double ans){
        if(!mp.count(src) || !mp.count(dest))return -1;
        if(src==dest)return ans;
        vis.insert(src);
        for(auto& x : mp[src])if(!vis.count(x.first)){
            double temp = dfs(mp,x.first,dest,vis,ans*x.second);
            if(temp!=-1)return temp;  
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string,vector<pair<string,double>>> mp;
        unordered_set<string> vis;
        int idx=0;
        for(const auto& v : equations){
            mp[v[0]].push_back({v[1],values[idx]});
            mp[v[1]].push_back({v[0],1.0/values[idx++]});
        }
        for(auto& q : queries){
            ans.push_back(dfs(mp,q[0],q[1],vis,1.0));
            vis.clear();
        }
        return ans;
    }
};