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
    long long prev = LLONG_MIN;

    bool inorder(TreeNode* root) {
        if (!root)
            return true;

        if (!inorder(root->left))
            return false;

        if (root->val <= prev)
            return false;
        prev = root->val;

        return inorder(root->right);
    }

    bool isValidBST(TreeNode* root) { return inorder(root); }
};

// class Solution {
// public:
//     vector<int> inorder(TreeNode* root, vector<int>& result) {
//         if (root != NULL) {
//             inorder(root->left, result);
//             result.push_back(root->val);
//             inorder(root->right, result);
//         }
//         return result;
//     }

//     bool isAscendingOrder(vector<int>& result) {
//         for (int i = 1; i < result.size(); i++) {
//             if (result[i] <= result[i - 1]) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     bool isValidBST(TreeNode* root) {
//         vector<int> result;
//         inorder(root, result);

//         return isAscendingOrder(result);
//     }
// };
