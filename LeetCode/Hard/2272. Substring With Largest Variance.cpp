class Solution {
public:
    int largestVariance(string s) {
        vector<int> count(26, 0);
        int maxVariance = 0;
        
        for (char& ch : s) {
            count[ch - 'a']++;
        }
        
        for (char first = 'a'; first <= 'z'; ++first) {
            for (char second = 'a'; second <= 'z'; ++second) {
                if (count[first - 'a'] == 0 || count[second - 'a'] == 0) {
                    continue;
                }
                
                int firstCount = 0;
                int secondCount = 0;
                bool pastLowFreq = false;
                
                for (const char& ch : s) {
                    if (ch == first) {
                        ++firstCount;
                    }
                    if (ch == second) {
                        ++secondCount;
                    }
                    
                    if (secondCount > 0) {
                        maxVariance = max(maxVariance, firstCount - secondCount);
                    } else {
                        if (pastLowFreq) {
                            maxVariance = max(maxVariance, firstCount - 1);
                        }
                    } 
                    
                    if (secondCount > firstCount) {
                        secondCount = 0;
                        firstCount = 0;
                        pastLowFreq = true;
                    }
                }
            }
        }
        
        return maxVariance;
    }
};