/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        vector<int> vis(101);
        vector<Node*> mp(101);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* u = q.front();q.pop();
            mp[u->val]=new Node(u->val);
            vis[u->val]=true;
            for(auto v : u->neighbors){
                if(vis[v->val])continue;
                q.push(v);
            }
        }
        vis=vector<int>(101);
        q.push(node);
        while(!q.empty()){
            Node* u = q.front();q.pop();
            if(vis[u->val])continue;
            vis[u->val]= true;
            for(auto v : u->neighbors){
                mp[u->val]->neighbors.push_back(mp[v->val]);
                if(!vis[v->val])q.push(v);
            }
        }
        return mp[node->val];
    }
};