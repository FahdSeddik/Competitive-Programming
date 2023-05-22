/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> ll;
        ListNode* ptr = head;
        while(ptr)ll.push_back(ptr->val),ptr=ptr->next;
        int ans=0;
        int n = ll.size();
        for(int i=0,j=n-1;j>=0;i++,j--)ans = max(ans,ll[i]+ll[j]);
        return ans;
    }
};