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
    void func(TreeNode* root, vector<vector<int>>& ans) {
        queue<TreeNode*> q;

        q.push(root);

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

            // reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        vector<int> temp;
        func(root, ans);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};