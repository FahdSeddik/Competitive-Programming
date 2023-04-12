class Solution {
public:
    string simplifyPath(string path) {
        string ans="/",t;
        list<string> ll;
        stringstream ss(path);
        while(getline(ss,t,'/')){
            if(t==".." ) {
                if(!ll.empty())ll.pop_back();
            }
            else if(t!="." && !t.empty()) ll.push_back(t);
        }
        while(ll.size()>1)ans+=ll.front()+"/",ll.pop_front();
        return ll.empty() ? ans:ans+=ll.front();
    }
};