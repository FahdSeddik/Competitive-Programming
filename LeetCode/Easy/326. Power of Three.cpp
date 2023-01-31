class Solution {
public:
    bool isPowerOfThree(int n) {
        // 3^19 largest num in 32 bit
        return n>0 && !(1162261467 % n);
    }
};