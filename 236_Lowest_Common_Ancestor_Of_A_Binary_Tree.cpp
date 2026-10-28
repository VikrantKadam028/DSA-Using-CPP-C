/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = nullptr;
    int func(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return 0;
        }

        int left = func(root->left, p, q);
        int right = func(root->right, p, q);

        int self = 0;
        if (root == p || root == q) {
            self = 1;
        }
        int total = self + left + right;
        if (ans == nullptr && total == 2) {
            ans = root;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;

        func(root, p, q);
        return ans;
    }
};