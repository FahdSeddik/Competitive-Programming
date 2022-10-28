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
    ListNode* head;
    void merge2(ListNode*& l2){
        if(head->val >= l2->val){
            ListNode* temp = l2->next;
            l2->next=head;
            head=l2;
            l2=temp;
        }
        ListNode* p1=head,*p2=l2;
        if(!p2)return;
        while(p1 && p2){
            if(!p1->next){
                p1->next=p2;
                return;
            }
            if(p1->val <= p2->val && p1->next->val >= p2->val){
                ListNode* temp1 = p1->next,*temp2 = p2->next;
                p1->next = p2;
                p2 = temp2;
                p1=p1->next;
                p1->next = temp1;
            }else{
                p1=p1->next;
            }
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())return nullptr;
        int i=0;
        while(i<lists.size() && !lists[i])i++;
        if(i<lists.size())head=lists[i],i++;
        for(;i<lists.size();i++)if(lists[i])merge2(lists[i]);
        return head;
    }
};