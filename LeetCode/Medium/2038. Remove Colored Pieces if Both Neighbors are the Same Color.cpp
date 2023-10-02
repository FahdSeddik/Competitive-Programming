class Solution {
public:
    bool winnerOfGame(string colors) {
        int al=0,b=0,cnt=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                cnt++;
            }else{
                if(colors[i-1]=='A') al+=max(0,cnt-1);
                else b+=max(0,cnt-1);
                cnt=0;
            }
        }
        if(colors.back()=='A')al+=max(0,cnt-1);
        else b+=max(0,cnt-1);
        return al>b;
    }
};