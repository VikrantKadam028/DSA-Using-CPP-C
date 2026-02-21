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
    TreeNode* head = nullptr;
    TreeNode* tail = nullptr;

    TreeNode* createNode(int data) { return new TreeNode(data); }

    void appendLast(TreeNode* nn) {
        if (head == nullptr) {
            head = tail = nn;
            return;
        }
        tail->right = nn;
        tail->left = nullptr;
        tail = nn;
    }

    void getPreorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr)
            return;
        result.push_back(root->val);
        getPreorder(root->left, result);
        getPreorder(root->right, result);
    }

    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        vector<int> vals;
        getPreorder(root, vals);

        head = tail = nullptr;

        for (int i = 0; i < vals.size(); i++) {
            appendLast(createNode(vals[i]));
        }

        root->val = head->val;
        root->left = nullptr;
        root->right = head->right;
    }
};
