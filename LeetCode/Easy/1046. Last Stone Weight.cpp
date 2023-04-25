class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i : stones)pq.push(i);
        int ans=0;
        while(!pq.empty()){
            int stone1=pq.top();pq.pop();
            if(pq.empty())return stone1;
            int stone2 = pq.top();pq.pop();
            if(stone1==stone2)continue;
            pq.push(stone1-stone2);
        }
        return pq.empty() ? 0:pq.top();
    }
};