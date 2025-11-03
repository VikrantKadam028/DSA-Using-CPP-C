/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val)
                return i;
        }
        return -1;
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,
                     int& postIndex, int left, int right) {
        if (left > right)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postIndex]);
        postIndex--;
        if (left == right)
            return root;
        int inIndex = search(inorder, left, right, root->val);
        root->right = helper(inorder, postorder, postIndex, inIndex + 1, right);
        root->left = helper(inorder, postorder, postIndex, left, inIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        return helper(inorder, postorder, postIndex, 0, inorder.size() - 1);
    }
};
