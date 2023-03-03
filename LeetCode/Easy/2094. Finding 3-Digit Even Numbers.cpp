class Solution {
public:
    
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans,freq(10);
        for(const auto& i : digits)freq[i]++;
        for(int i=100,j=0;i<=999;i+=2){
            vector<int> cnt(10);
            int temp = i;
            while(temp)cnt[temp%10]++,temp/=10;
            for(j=0;j<10;j++){
                if(cnt[j]>freq[j])break;
            }
            if(j==10)ans.push_back(i);
        }
        return ans;
    }
};