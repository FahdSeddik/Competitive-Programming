class Solution {
public:
    bool can_move(string& s1,string& s2){
        int diff=0;
        for(int i=0;i<8;i++){
            if(s1[i]!=s2[i])diff++;
            if(diff>1)break;
        }
        return diff==1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,vector<string>> adj;
        if(!bank.size())return -1;
        if(start==end)return 0;
        for(int i=0;i<bank.size();i++){
            if(can_move(start,bank[i]))adj[start].push_back(bank[i]);
        }
        for(int i=0;i<bank.size()-1;i++){
            for(int j=i+1;j<bank.size();j++){
                if(can_move(bank[i],bank[j]))adj[bank[i]].push_back(bank[j]);
            }
        }
        queue<string> q;
        q.push(start);
        int size=1,depth=1;
        for(;!q.empty();++depth,size=q.size()){
            while(size--){
                string cur=q.front();q.pop();
                for(string s : adj[cur]){
                    if(s==end)return depth;
                    q.push(s);
                }
            }
        }
        return -1;
    }
};