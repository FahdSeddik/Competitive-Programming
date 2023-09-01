class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0;
        vector<string> current;
        int cur_size = 0;
        while(i<words.size()){
            string word = words[i];
            if(cur_size+current.size()+word.size()<=maxWidth){
                current.push_back(word);
                cur_size+=word.size();
            }else{
                //justify
                int spaces = (maxWidth-cur_size)/max((int)current.size()-1,1);
                if(spaces==0)spaces=1;
                int leftover = maxWidth-cur_size-spaces*(current.size()-1);
                vector<int> zyadat(current.size()-1,spaces);
                int k=0;
                while(leftover && zyadat.size()){
                    zyadat[k]++;
                    leftover--;
                    k=(k+1)%zyadat.size();
                }
                string candidate="";
                if(current.size()>1){
                    candidate+=current[0]+string(zyadat[0],' ');
                    for(int j=1;j<current.size()-1;j++){
                        candidate+=current[j]+string(zyadat[j],' ');
                    }
                    if(current.size()>=2){
                        candidate+=current.back();
                    }
                }else{
                    candidate+=current[0]+string(leftover,' ');
                }
                ans.push_back(candidate);
                //clear current
                current.clear();
                //append word
                current.push_back(word);
                //update cur_size
                cur_size=word.size();
            }
            i++;
        }
        string temp="";
        if(current.size()){
            for(int j=0;j<current.size()-1;j++){
                temp+=current[j]+' ';
            }
            temp+=current.back();
            temp+=string(maxWidth-temp.size(),' ');
        }else{
            vector<string> left_over_words;
            for(auto c : ans.back()){
                if(c==' ')if(temp.size())left_over_words.push_back(temp),temp="";
                else temp+=c;
            }
            if(temp.size())left_over_words.push_back(temp);
            temp="";
            for(int j=0;j<left_over_words.size()-1;j++){
                temp+=left_over_words[j]+' ';
            }
            temp+=left_over_words.back();
            temp+=string(maxWidth-temp.size(),' ');
        }
        ans.push_back(temp);
        return ans;
    }
};