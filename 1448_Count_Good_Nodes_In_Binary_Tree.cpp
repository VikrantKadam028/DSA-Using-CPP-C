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
    void func(TreeNode* root, vector<int>& ans, vector<int>& temp, int val) {
        if (root == nullptr)
            return;

        temp.push_back(root->val);

        int x = temp[temp.size() - 1];
        bool isGreater = (val > x);

        for (int i = 0; i < temp.size() - 1; i++) {
            if (temp[i] > x) {
                isGreater = true;
                break;
            }
        }

        if (!isGreater) {
            ans.push_back(x);
        }

        func(root->left, ans, temp, val);
        func(root->right, ans, temp, val);

        temp.pop_back();
        return;
    }
    int goodNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;

        vector<int> ans;
        vector<int> temp;
        ans.push_back(root->val);
        int val = root->val;
        if (root->left != nullptr) {
            func(root->left, ans, temp, val);
        }

        if (root->right != nullptr) {
            func(root->right, ans, temp, val);
        }
        return ans.size();
    }
};