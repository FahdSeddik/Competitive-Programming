class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int> ans(deck.size());
        queue<int> q;
        for(int i=0;i<deck.size();i++)q.push(i);
        int index=0;
        while(!q.empty()){
            ans[q.front()]=deck[index++];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};