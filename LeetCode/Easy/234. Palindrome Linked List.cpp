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

    bool isPalindrome(ListNode* head) {
        ListNode* fast=head,*slow=head;
        while(fast && fast->next){
            fast = fast->next->next,slow=slow->next;
        }
        ListNode* prev = nullptr;
        while(slow){
            ListNode* temp = slow->next;
            slow->next=prev,prev=slow,slow=temp;
        }
        for(;head && prev;head=head->next,prev=prev->next)if(head->val != prev->val)return false;
        return true;
    }
};