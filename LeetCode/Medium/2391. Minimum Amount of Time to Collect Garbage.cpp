class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int metal=0,paper=0,glass=0;
        int mc=0,pc=0,gc=0;
        int mh=0,ph=0,gh=0;
        for(int i=0;i<garbage.size()-1;i++){
            for(auto c : garbage[i]){
                if(c=='M')mc++;
                else if(c=='P')pc++;
                else gc++;
            }
            if(mc){
                metal+=mh+mc;
                mh=0,mc=0;
            }
            if(gc){
                glass+=gh+gc;
                gh=0,gc=0;
            }
            if(pc){
                paper+=ph+pc;
                ph=0,pc=0;
            }
            mh+=travel[i],ph+=travel[i],gh+=travel[i];
        }
        for(auto c : garbage.back()){
            if(c=='M')mc++;
            else if(c=='P')pc++;
            else gc++;
        }
        if(mc){
            metal+=mh+mc;
            mh=0,mc=0;
        }
        if(gc){
            glass+=gh+gc;
            gh=0,gc=0;
        }
        if(pc){
            paper+=ph+pc;
            ph=0,pc=0;
        }
        return metal+paper+glass;
    }
};