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
    ListNode* head,*ans;
public:
    void addtwo(ListNode* l1,ListNode* l2,int carry=0){
        if(!l1 && !l2 && !carry)return;
        if(!l1 && !l2 && carry){
            head->next=new ListNode(carry);
            return;
        }
        if(!l1){
            int res=carry+l2->val;
            head->next=new ListNode(res%10);
            head=head->next;
            res/=10;
            addtwo(nullptr,l2->next,res);
            return;
        }
        if(!l2){
            int res=carry+l1->val;
            head->next=new ListNode(res%10);
            head=head->next;
            res/=10;
            addtwo(l1->next,nullptr,res);
            return;
        }
        
        int res = carry+l2->val+l1->val;
        head->next = new ListNode(res%10);
        head=head->next;
        res/=10;
        addtwo(l1->next,l2->next,res);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        head=new ListNode();
        ans=head;
        addtwo(l1,l2);
        return ans->next;
    }
};