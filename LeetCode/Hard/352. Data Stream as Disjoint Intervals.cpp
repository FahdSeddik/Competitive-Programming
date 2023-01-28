class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {}
    void addNum(int value) { st.insert(value); }
    vector<vector<int>> getIntervals() {
        if (st.empty()) {
            return {};
        }
        vector<vector<int>> ans;
        int start = -1, last = -1;
        for (int val : st) {
            if (start < 0) {
                start = last = val;
            } else if (val-last==1) {
                last = val;
            } else {
                ans.push_back({start, last});
                start = last = val;
            }
        }
        ans.push_back({start, last});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */