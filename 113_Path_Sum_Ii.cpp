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
    void func(TreeNode* root, int targetSum, vector<vector<int>>& ans,
              vector<int>& temp, int tempSum) {
        if (root == nullptr)
            return;

        tempSum += root->val;
        temp.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == tempSum) {
                ans.push_back(temp);
            }
        }

        func(root->left, targetSum, ans, temp, tempSum);
        func(root->right, targetSum, ans, temp, tempSum);

        temp.pop_back();
       
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return {};

        vector<vector<int>> ans;
        vector<int> temp;

        func(root, targetSum, ans, temp, 0);

        return ans;
    }
};