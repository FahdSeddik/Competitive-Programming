class Solution {
public:
    std::vector<int> findMode(TreeNode* root) {
        in_order_traversal(root);
        return modes;
    }
private:
    int current_val = 0;
    int current_count = 0;
    int max_count = 0;
    std::vector<int> modes;

    void in_order_traversal(TreeNode* node) {
        if (!node) return;
        
        in_order_traversal(node->left);
        
        current_count = (node->val == current_val) ? current_count + 1 : 1;
        if (current_count == max_count) {
            modes.push_back(node->val);
        } else if (current_count > max_count) {
            max_count = current_count;
            modes = { node->val };
        }
        current_val = node->val;

        in_order_traversal(node->right);
    }
};