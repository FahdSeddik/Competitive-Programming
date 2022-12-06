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

    ListNode* oddEvenList(ListNode* head) {
        if(!head)return nullptr;
        ListNode* ptr1,*ptr2,*ans,*temp;
        ans=head;
        ptr1=ans;
        if(ptr1->next)ptr2=ptr1->next,ptr1->next=nullptr,temp=ptr2;
        else return ptr1;
        int index=3;
        while(ptr1->next ||ptr2->next){
            if(index%2==1){
                if(ptr2->next)ptr1->next=ptr2->next,ptr1=ptr1->next,ptr2->next=nullptr;
            }else{
                if(ptr1->next)ptr2->next=ptr1->next,ptr2=ptr2->next,ptr1->next=nullptr;
            }
            index++;
        }
        ptr1->next=temp;
        return ans;
    }
};