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
    int length;
public:
    Solution(ListNode* head) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        length=0;
        this->head=head;
        while(head)length++,head=head->next;
    }
    
    int getRandom() {
        int v = rand()%length;
        ListNode* ptr = head;
        while(v--)ptr=ptr->next;
        return ptr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */