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
    void allPaths(TreeNode* root, string path, vector<string>& pathval) {
        if (root->left == nullptr && root->right == nullptr) {
            pathval.push_back(path);
            return;
        }

        if (root->left) {
            allPaths(root->left, path + to_string(root->left->val), pathval);
        }

        if (root->right) {
            allPaths(root->right, path + to_string(root->right->val), pathval);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        int total = 0;
        vector<string> PathValues;

        string path = to_string(root->val);

        allPaths(root, path, PathValues);

        for (int i = 0; i < PathValues.size(); i++) {
            // bitset<32> bits(PathValues[i]);
            int bits = stoi(PathValues[i], nullptr, 2);
            total += bits; 
        }

        return total;
    }
};
