/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return nullptr;
        queue<Node*> q;
        q.push(root);
        int size=1;
        for(;!q.empty();size=q.size()){
            Node* prev = nullptr;
            while(size--){
                Node* u = q.front();q.pop();
                u->next = prev;
                prev = u;
                if(u->right)q.push(u->right);
                if(u->left)q.push(u->left);
            }
        }
        return root;
    }
};