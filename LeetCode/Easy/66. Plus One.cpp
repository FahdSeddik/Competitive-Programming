class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]==9){
                carry=1;
                digits[i]=0;
            }else{
                digits[i]++;
                carry--;
                break;
            }
        }
        if(carry<=0)return digits;
        vector<int> dg(digits.size()+1);
        dg[0]=carry;
        for(int i=1;i<dg.size();i++)dg[i]=digits[i-1];
        return dg;
    }
};