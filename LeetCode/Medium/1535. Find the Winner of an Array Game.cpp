class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size())return *max_element(arr.begin(),arr.end());
        else{
            int cur_mx=0,streak=1;
            if(arr[0]>arr[1])cur_mx=arr[0];
            else cur_mx=arr[1];
            if(k==streak)return cur_mx;
            int i=2;
            while(true){
                if(cur_mx>=arr[i])streak++;
                else cur_mx=arr[i],streak=1;
                if(streak==k)return cur_mx;
                i=(i+1)%arr.size();
            }
        }
        return 0;
    }
};