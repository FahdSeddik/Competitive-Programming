class Solution {
public:
    int countOdds(int low, int high) {
        // 1 2 3 4 5 6      (6-1)/2+1
        // 1 2 3 4 5        (5-1)/2+1
        // 2 3 4 5 6 7      (7-2)/2+1
        // 2 3 4 5 6        (6-2)/2
        if(low%2==0 && high%2==0)return (high-low)/2;
        return (high-low)/2+1;
    }
};