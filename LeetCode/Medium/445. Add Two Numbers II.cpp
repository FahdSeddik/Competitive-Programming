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
    ListNode* helper(ListNode* l1, ListNode* l2) 
    {
        int carry=0;
        ListNode* res=NULL;
        stack<int> s1,s2;
        while(l1!=NULL)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        while(!s1.empty()||!s2.empty()||carry!=0)
        {
            int a= !s1.empty() ? s1.top() : 0;
            int b= !s2.empty() ? s2.top() : 0;
            int sum=a+b+carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newNode = new ListNode(digit);
            newNode->next = res;
            res = newNode;
            if(!s1.empty())
            s1.pop();
            if(!s2.empty())
            s2.pop();
        }
        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ans=helper(l1,l2);
        return ans;
    }
};