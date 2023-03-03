class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum=0;
        for(const auto& v : target){
            pq.push(v);
            sum+=v;
        }
        while(pq.top()!=1){
            sum-=pq.top();
            if(sum==0 ||  sum>=pq.top())return false;
            int mx = pq.top()%sum;
            if(sum!=1  &&  mx==0)return false;
            pq.pop();
            pq.push(mx);
            sum+=mx;
        }
        return true;
    }
};