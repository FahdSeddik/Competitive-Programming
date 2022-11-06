class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
		//Booth Algorithm for string rotation
            int n=s.size();
            vector<int> f(2*n,-1);
            int p=0;
            for(int j=1;j<2*n;j++){
                int i=f[j-p-1];
                while (i!=-1 && s[j%n]!=s[(p+i+1)%n]){
                    if(s[j%n] <s[(p+i+1)%n]){
                        p=j-i-1;
                    }
                    i=f[i];
                }
                if (i==-1 && s[j%n]!=s[(p+i+1)%n]){
                    if(s[j%n] < s[(p+i+1)%n]){
                        p=j;
                    }
                    f[j-p]=-1;
                }
                else{
                    f[j-p]=i+1;
                }
            }
            return s.substr(p,s.size())+s.substr(0,p);
        }
        sort(s.begin(),s.end());
        return s;
    }
};