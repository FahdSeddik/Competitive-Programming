/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bs(MountainArray& ma,int t,int start,int end,bool rev){
        int l=start,r=end;
        while(l<r){
            int mid=(l+r)/2;
            int v = ma.get(mid);
            if(v==t)return mid;
            else if(v<t)rev ? r=mid:l=mid+1;
            else rev ? l=mid+1:r=mid;
        }
        return ma.get(l)==t ? l:-1;
    }
    int findInMountainArray(int target, MountainArray &ma) {
        int n = ma.length();
        int l=0,r=n-1;
        int peak=-1;
        while(l<r){
            int mid = (l+r)/2;
            int v0 = ma.get(mid-1),v1=ma.get(mid),v2=ma.get(mid+1);
            if(v0<=v1 && v1>=v2) {
                peak=mid;
                break;
            }
            else if(v1<=v2)l=mid+1;
            else r=mid;
        }
        int a = bs(ma,target,0,peak,0);
        if(a!=-1)return a;
        a=bs(ma,target,peak+1,n-1,1);
        return a==-1 ? -1:a;
    }
};