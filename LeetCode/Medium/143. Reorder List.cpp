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
    void reorderList(ListNode* head) {
        ListNode*slow=head,*fast=head;
        while(fast && fast->next)slow=slow->next,fast=fast->next->next;
        ListNode*cur=slow->next,*prev=nullptr,*next=nullptr;
        slow->next=nullptr;
        while(cur)next=cur->next,cur->next=prev,prev=cur,cur=next;
        ListNode*first=head,*second=prev;
        while(first && second){
            ListNode* n1=first->next,*n2=second->next;
            first->next=second,second->next=n1;
            first=n1,second=n2;
        }
    }
};