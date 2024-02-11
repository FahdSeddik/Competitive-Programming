class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string nums = "123456789";
        vector<int> ans;
        int ld = 0,t=low,hd=0;
        while(t)ld++,t/=10;
        t=high;
        while(t)hd++,t/=10;
        for(int d=ld;d<=hd;d++){
            for(int l=0;l+d<=9;l++){
                int num = stoi(nums.substr(l,d));
                if(num>=low && num<=high)ans.push_back(num);
            }
        }
        return ans;
    }
};