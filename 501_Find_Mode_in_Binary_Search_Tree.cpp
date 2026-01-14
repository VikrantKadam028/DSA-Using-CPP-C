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
    void inorder(TreeNode* root, vector<int>& result) {
        if (root != NULL) {
            inorder(root->left, result);
            result.push_back(root->val);
            inorder(root->right, result);
        }
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        inorder(root, result);

        unordered_map<int, int> freq;

        for (int no : result) {
            freq[no]++;
        }

        vector<int> ans;
        int maxFreq = 0;

        for (auto& it : freq) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                ans.clear();             
                ans.push_back(it.first); 
            } else if (it.second == maxFreq) {
                ans.push_back(it.first); 
            }
        }

        return ans;
    }
};
