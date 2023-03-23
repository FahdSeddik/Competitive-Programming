class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        for(int i=0;i<m && n;i++){
            if(!flowerbed[i] && (!i || !flowerbed[i-1]) && (i==m-1 || !flowerbed[i+1])){
                flowerbed[i]=1,n--;
            }
        }
        return !n;
    }
};