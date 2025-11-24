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
    void getInorder(TreeNode* root, vector<int>& result, int &count, int k) {
        if (!root || count == k) 
            return;

        getInorder(root->left, result, count, k);

        if (count == k) return;  
        result.push_back(root->val);
        count++;

        getInorder(root->right, result, count, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        int count = 0;

        getInorder(root, inorder, count, k);

        return inorder[k-1];
    }
};
