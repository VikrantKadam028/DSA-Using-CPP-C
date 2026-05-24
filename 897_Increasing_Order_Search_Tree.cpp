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
    void getInorder(vector<int>& inorder, TreeNode* root) {
        if (root == nullptr)
            return;
        getInorder(inorder, root->left);
        inorder.push_back(root->val);
        getInorder(inorder, root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> result;
        getInorder(result, root);

        int n = result.size();

        TreeNode* newRoot = new TreeNode(result[0]);
        TreeNode* temp = newRoot;
        for (int i = 1; i < n; i++) {
            TreeNode* newNode = new TreeNode(result[i]);
            temp->right = newNode;
            temp = newNode;
        }

        return newRoot;
    }
};