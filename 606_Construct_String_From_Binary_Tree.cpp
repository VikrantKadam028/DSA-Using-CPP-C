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
    void func(TreeNode* root, string& str) {
        if (root == nullptr) {
            return;
        }
        str.push_back('(');
        str += to_string(root->val);

        if (root->left == nullptr && root->right != nullptr) {
            str += "()";
        }

        if (root->left != nullptr) {
            func(root->left, str);
        }
        if (root->right != nullptr) {
            func(root->right, str);
        }

        str += ")";
        return;
    }
    string tree2str(TreeNode* root) {
        if (root == nullptr)
            return "";
        string str = "";
        str += to_string(root->val);
        if (root->left == nullptr && root->right != nullptr) {
            str += "()";
        }

        if (root->left != nullptr) {
            func(root->left, str);
        }
        if (root->right != nullptr) {
            func(root->right, str);
        }
        return str;
    }
};