class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, int> headMask;
        for (const auto &idea : ideas) {
            headMask[idea.substr(1)] |= 1 << (idea[0] - 'a');
        }
        int cnt[26][26][2] ={{{0}}};
        for (auto &[k, mask] : headMask) {
            for (int i = 0; i < 26; ++i) {
                for (int j = i + 1; j < 26; ++j) {
                    if (((mask >> i) & 1) ^ ((mask >> j) & 1)) {
                        ++cnt[i][j][(mask >> i) & 1];
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                ans += 2ll * cnt[i][j][0] * cnt[i][j][1];
            }
        }
        return ans;
    }
};