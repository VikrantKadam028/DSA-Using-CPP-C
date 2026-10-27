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
    void levelOrder(TreeNode* root, vector<vector<int>>& ans) {
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int lvlSize = q.size();
            vector<int> temp;

            while (lvlSize--) {
                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if (t->left != nullptr) {
                    q.push(t->left);
                }

                if (t->right != nullptr) {
                    q.push(t->right);
                }
            }

            ans.push_back(temp);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        vector<vector<int>> ans;

        levelOrder(root, ans);

        return ans;
    }
};