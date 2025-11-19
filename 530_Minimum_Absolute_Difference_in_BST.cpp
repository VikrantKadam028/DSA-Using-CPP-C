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
    void getInorder(TreeNode* root, vector<int>& nodeVal) {
        if (!root)
            return;
        getInorder(root->left, nodeVal);
        nodeVal.push_back(root->val);
        getInorder(root->right, nodeVal);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodeVal;
        getInorder(root, nodeVal);

        int diff = INT_MAX;
        for (int i = 1; i < nodeVal.size(); i++) {
            diff = min(diff, nodeVal[i] - nodeVal[i - 1]);
        }
        return diff;
    }
};
