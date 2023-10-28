class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1)return 0;
        int length = 1<<(n-2);
        if(k<=length)return kthGrammar(n-1,k);
        else return !kthGrammar(n-1,k-length);
    }
};
/*
0
01
0110
01101001
0110100110010110
01101001100101101001011001101001
0110100110010110100101100110100110010110011010010110100110010110

*/