class Solution {
public:
    double average(vector<int>& salary) {
        int mn=INT_MAX,mx=INT_MIN,tot=0;
        for(auto v : salary)mn=min(mn,v),mx=max(mx,v),tot+=v;
        return double(tot-mx-mn)/(salary.size()-2);
    }
};