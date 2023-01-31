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
    ListNode* reverseList(ListNode* head) {
        if(!head)return nullptr;
        ListNode* ptr=head,*temp=head->next;
        ptr->next=nullptr;
        while(temp){
            ListNode* t = temp->next;
            temp->next = ptr;
            ptr=temp,temp=t;
        }
        return ptr;
    }
};