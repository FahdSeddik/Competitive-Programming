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
    pair<ListNode*,ListNode*> reverse(ListNode* head,int number){
        //reverse list for given number of nodes
        //starting from head
        //returns starting node and ending node
        if(!head)return {nullptr,nullptr};
        ListNode* c = head;
        int ch = number;
        //check if available
        while(c && ch)c=c->next,ch--;
        if(ch)return {head,nullptr};
        ListNode* prev =nullptr;
        ListNode* ptr = head;
        ListNode* nxt = ptr->next;
        ListNode* temp = nxt->next;
        for(int i=0;i<number && nxt;){
            //cout<<ptr->val;
            ptr->next = prev;
            nxt->next = ptr;
            prev=ptr;
            ptr=nxt;
            nxt = temp;
            if(nxt)temp = nxt->next;
            if(i==0)i+=2;
            else i++;
        }
        pair<ListNode*,ListNode*> pr =  reverse(nxt,number);
        head->next = pr.first;
        return {ptr,nxt};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        return reverse(head,k).first;
    }
};