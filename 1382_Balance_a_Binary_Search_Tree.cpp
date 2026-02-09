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
    void inorder(vector<int>& inorderVec, TreeNode* root) {
        if (root != NULL) {
            inorder(inorderVec, root->left);
            inorderVec.push_back(root->val);
            inorder(inorderVec, root->right);
        }
    }

    TreeNode* TransformToBST(vector<int>& inorderVec, int start, int end) {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;
        TreeNode* root2 = new TreeNode(inorderVec[mid]);
        root2->left = TransformToBST(inorderVec, start, mid - 1);
        root2->right = TransformToBST(inorderVec, mid + 1, end);
        return root2;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVec;

        inorder(inorderVec, root);

        int start = 0;
        int end = inorderVec.size() - 1;

        TreeNode* root2 = TransformToBST(inorderVec, start, end);
        return root2;
    }
};
