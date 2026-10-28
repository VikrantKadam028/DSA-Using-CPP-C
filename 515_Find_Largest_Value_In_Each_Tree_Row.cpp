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
    void func(TreeNode* root, vector<int>& ans) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int lvl = q.size();
            int maxi = INT_MIN;

            while (lvl--) {
                TreeNode* t = q.front();
                q.pop();
                maxi = max(maxi, t->val);

                if (t->left != nullptr) {
                    q.push(t->left);
                }

                if (t->right != nullptr) {
                    q.push(t->right);
                }
            }

            ans.push_back(maxi);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<int> ans;
        func(root, ans);

        // vector<int> result;
        // for (auto it : ans) {
        //     if (it.empty())
        //         continue;

        //     auto it2 = max_element(it.begin(), it.end());
        //     result.push_back(*it2);
        // }
        return ans;
    }
};