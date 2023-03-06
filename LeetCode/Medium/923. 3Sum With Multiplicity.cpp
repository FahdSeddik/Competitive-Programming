class Solution {
public:
    int threeSumMulti(vector<int>& arr, int t) {        
        int freq[101] = {0}, MAX = 0, ans = 0, mod = 1000000007;
        for(const auto& num : arr) freq[num]++, MAX = max(MAX, num);
        for(int i = 0; i <= MAX; i++){
            if(i + i + i == t) ans += (((long)freq[i] * (freq[i] - 1) * (freq[i] - 2)) / 6) % mod;
            for(int j = i + 1; j <= MAX; j++)               
                if(i + i + j == t) ans += (freq[i] * (freq[i] - 1) >> 1) * freq[j];
                else if(i + j + j == t) ans += (freq[j] * (freq[j] - 1) >> 1) * freq[i];
                else ans += (t - i - j > j  && t - i - j <= MAX ? freq[i] * freq[j] * freq[t - i - j] : 0) % mod;            
        }
        return ans;
    }
};