class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	/* faster than 100% less than 72.67% memory O(nlogn)
        for(int i=m;i<m+n;i++)nums1[i]=nums2[i-m];
        sort(nums1.begin(),nums1.end());
	*/

	// faster than 43.81% less than 30.63% O(n)
	int i=m-1,j=n-1,index=m+n-1;
        while(j>=0){
            nums1[index--] = (i>=0 && nums1[i]>nums2[j]) ? nums1[i--]:nums2[j--];
        }
    }
};