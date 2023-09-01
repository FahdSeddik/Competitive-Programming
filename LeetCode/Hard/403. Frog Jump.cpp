class Solution {
public:
    bool canCross(vector<int>& stones) {
        bool bCheck = false;
        return canCross(stones, 0, 0, stones.size(), bCheck);
    }

    bool canCross(vector<int>& stones, int i, int k, int n, bool& bCheck){
        if (i == n-1)
            return true;
        if (stones[i+1] > stones[i] + k + 2){
            bCheck = true;
            return false;
        }
        static vector<int> dirs = {1,0,-1};
        for (int dir : dirs){
            int next = dir + k;
            if (binary_search(stones.begin(), stones.end(), stones[i] + next)){
                int j = i + 1;
                while (j < n && stones[j] != stones[i] + next){
                    if (stones[j] > stones[i] + next)
                        break;
                    j++;
                }
                if (j < n && stones[j] == stones[i] + next){
                    if (canCross(stones, j, next, n, bCheck))
                        return true;
                    if (bCheck)
                        return false;
                }
            }
        }
        return false;
    }
};