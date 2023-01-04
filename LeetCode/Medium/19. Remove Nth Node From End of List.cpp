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
    int end,to;
public:
    void rem(ListNode* ptr,int cur=1){
        if(!ptr)return;
        if(!ptr->next){
            if(cur==to)end=-2;
            else end = cur-to;
            return;
        }
        rem(ptr->next,cur+1);
        if(cur==end){
            ptr->next=ptr->next->next;
            end=-1;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;
        if(n==1 && !head->next)return head->next;
        end = INT_MAX,to=n;
        rem(head);
        if(end==-2)return head->next;
        return head;
    }
};