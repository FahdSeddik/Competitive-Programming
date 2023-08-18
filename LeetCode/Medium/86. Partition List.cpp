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
    ListNode* partition(ListNode* head, int x) {
        ListNode before(0),after(0);
        ListNode* before_ptr = &before,*after_ptr=&after;
        while(head){
            if(head->val<x){
                before_ptr->next = head;
                before_ptr = head;
            }else{
                after_ptr->next = head;
                after_ptr = head;
            }
            head = head->next;
        }
        after_ptr->next = nullptr;
        before_ptr->next = after.next;
        return before.next;
    }
};