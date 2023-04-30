class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {        
        multimap<int,int> m;
        for(int a:nums){
            int value=0,temp=a;
            if(a==0) value=mapping[0];
            else{
                int t=1;
                while(a){
                    value+=mapping[a%10]*t;
                    t*=10, a/=10;
                }
            }
            m.insert(make_pair(value,temp));
        }
        nums.clear();
        for(auto&[v1,v2]:m){
            nums.push_back(v2);
        }
        return nums;
    }
};