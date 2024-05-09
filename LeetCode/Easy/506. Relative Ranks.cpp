class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> scoreIndexPairs(n);
        for (int i = 0; i < n; ++i) {
            scoreIndexPairs[i] = {score[i], i};
        }
        sort(scoreIndexPairs.rbegin(), scoreIndexPairs.rend());
        vector<string> ranks(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ranks[scoreIndexPairs[i].second] = "Gold Medal";
            } else if (i == 1) {
                ranks[scoreIndexPairs[i].second] = "Silver Medal";
            } else if (i == 2) {
                ranks[scoreIndexPairs[i].second] = "Bronze Medal";
            } else {
                ranks[scoreIndexPairs[i].second] = to_string(i + 1);
            }
        }
        return ranks;
    }
};