class Solution {
public:
    static bool closeStrings(const string &word1, const string &word2) {
        constexpr uint8_t ASIZE = 26;
        const unsigned n = word1.length();
        if (n != word2.length()) return false;
        unsigned freqs1[ASIZE] = {}, freqs2[ASIZE] = {};
        for (unsigned i = 0; i < n; i++) {
            freqs1[word1[i]-'a']++;
            freqs2[word2[i]-'a']++;
        }
        for (uint8_t c = 0; c < ASIZE; c++) {
            const auto f1 = freqs1[c];
            auto &f2 = freqs2[c];
            if (f1 == f2) continue;
            if (f1 == 0 || f2 == 0) return false;
            uint8_t d;
            for (d = c + 1u; d < ASIZE && (freqs2[d] != f1 || freqs2[d] == freqs1[d]); d++);
            if (d >= ASIZE) return false;
            if (d != c) swap(freqs2[d], f2);
        }
        return true;
    }
};

static const int fastio = [](){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();