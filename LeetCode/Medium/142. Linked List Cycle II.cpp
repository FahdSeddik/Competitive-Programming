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
    ListNode *detectCycle(ListNode *head) {
        if(!head)return nullptr;
        ListNode* fast=head,*slow=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                while(head!=fast){
                    head=head->next;
                    fast=fast->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};