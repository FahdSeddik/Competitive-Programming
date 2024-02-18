/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int ans=0;
    unordered_map<int,int> imp;
    unordered_map<int,vector<int>> company;
public:
    void dfs(int src){
        ans+=imp[src];
        for(int e : company[src])dfs(e);
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(const auto& x : employees){
            company[x->id]=x->subordinates;
            imp[x->id]=x->importance;
        }
        dfs(id);
        return ans;
    }
};