/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int key) {
        if (!root)
            return new TreeNode(key);
        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        while (root != NULL) {
            prev = root;
            if (key == root->val) {
                return root;
            } else if (key < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        TreeNode* newNode = new TreeNode(key);
        if (key < prev->val) {
            prev->left = newNode;
        } else {
            prev->right = newNode;
        }
        return curr;
    }
};
