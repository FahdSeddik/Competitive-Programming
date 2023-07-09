class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0;
        int l=0;
        int ts=0,fs=0;
        for(int i=0;i<answerKey.size();i++){
            if(answerKey[i]=='T')ts++;
            else fs++;
            while(min(fs,ts)>k){
                if(answerKey[l++]=='T')ts--;
                else fs--;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};