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
    ListNode* h;
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)return nullptr;
        if(!list1)return list2;
        if(!list2)return list1;
        ListNode* head;
        if(list1->val<=list2->val){
            head=list1;
            list1=list1->next;
        }else{
            head=list2;
            list2=list2->next;
        }
        h=head;
        while(list1 || list2){
            if(!list1){
                head->next = list2;
                break;
            }
            if(!list2){
                head->next = list1;
                break;
            }
            if(list1->val <=list2->val){
                head->next = list1;
                list1 = list1->next;
            }else{
                head->next = list2;
                list2 = list2->next;
            }
            head=head->next;
        }
        return h;
    }
};