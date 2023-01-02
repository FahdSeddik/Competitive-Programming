class Solution {
public:
    bool detectCapitalUse(string word) {
        int u=0,l=0;
        bool fu=true;
        if(word[0]>='a')fu=false;
        for(int i=1;i<word.size();i++)if(word[i]>='a')l++;else u++;
        return (u==0) || (fu && l==0);
    }
};