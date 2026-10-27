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
        int isAlter = 0;

        while (!q.empty()) {
            int lvl = q.size();
            vector<int> temp;

            while (lvl--) {
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

            if (isAlter == 0) {
                ans.push_back(temp);
                isAlter = 1;
            } else if (isAlter == 1) {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                isAlter = 0;
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> ans;

        levelOrder(root, ans);

        return ans;
    }
};