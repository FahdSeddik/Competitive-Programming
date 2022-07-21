#include <iostream>
using namespace std;

int main(){
    int n,h,t,result=0;
    cin>>n>>h;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t>h)result+=2;
        else result++;
    }
    cout<<result<<"\n";
}