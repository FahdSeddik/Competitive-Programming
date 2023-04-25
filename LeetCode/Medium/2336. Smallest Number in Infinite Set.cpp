class SmallestInfiniteSet {
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> s;
    int ret;
public:
    SmallestInfiniteSet() {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        ret=1;
    }
    
    int popSmallest(int ans=0) {
        if(pq.empty() || pq.top()>ret){
            ret++;
            return ret-1;
        }
        ans=pq.top();
        pq.pop();
        s.erase(ans);
        return ans;
    }
    
    void addBack(int num) {
        if(ret<=num || s.count(num))return;
        s.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */