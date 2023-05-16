class Solution {
public:
    int findNthDigit(long long n) {
        long long start=1,size=1,step=9;
        while(n> size*step){
            n-=size*step,size++,step*=10,start*=10;
        }
        return to_string(start+(n-1)/size)[(n-1)%size]-'0';
    }
};