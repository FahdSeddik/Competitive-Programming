class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto a : asteroids){
            if(s.empty() || (s.top()<0 && a>0) || (s.top()<0 && a<0) || (s.top()>0 && a>0))s.push(a);
            else{
                while(!s.empty() && s.top()>0 && s.top()<abs(a))s.pop();
                if(s.empty() || s.top()<0)s.push(a);
                else if(s.top()==abs(a))s.pop();
            }
        }
        vector<int> ans(s.size());
        int i=s.size()-1;
        while(!s.empty())ans[i--]=s.top(),s.pop();
        return ans;
    }
};