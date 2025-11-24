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
    void getInorder(TreeNode* root, vector<int>& result) {
        if (!root)
            return;

        getInorder(root->left, result);
        result.push_back(root->val);
        getInorder(root->right, result);
    }

    int findSecondMinimumValue(TreeNode* root) {
        vector<int> inorder;
        getInorder(root, inorder);
        sort(inorder.begin(), inorder.end());

        if (inorder.size() < 2)
            return -1;
        int smallest = inorder[0];
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] != smallest) {
                return inorder[i];
            }
        }
        return -1;
    }
};
