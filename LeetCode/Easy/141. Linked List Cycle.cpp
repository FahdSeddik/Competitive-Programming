/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool check(ListNode * ptr1,ListNode* ptr2){
        if(!ptr2 || !ptr2->next)return false;
        if(ptr1==ptr2)return true;
        return check(ptr1->next,ptr2->next->next);
    }
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)return false;
        return check(head,head->next->next);
    }
};