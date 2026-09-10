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
    void getSum(TreeNode* root, int& NoOFNodes, int& sum) {
        if (root == nullptr)
            return;

        sum += root->val;
        NoOFNodes++;
        getSum(root->left, NoOFNodes, sum);
        getSum(root->right, NoOFNodes, sum);
    }

    void getInorder(TreeNode* root, vector<TreeNode*>& result) {
        if (root == nullptr)
            return;

        getInorder(root->left, result);
        result.push_back(root);
        getInorder(root->right, result);
    }

    TreeNode* search(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;

        if (root->val == key) {
            return root;
        }

        TreeNode* tempRoot = search(root->left, key);

        if (tempRoot != NULL)
            return tempRoot;

        return search(root->right, key);
    }

    int averageOfSubtree(TreeNode* root) {

        vector<TreeNode*> nums;
        getInorder(root, nums);

        int cnt = 0;

        for (TreeNode* n : nums) {

            int sum = 0;
            int NoOfNodes = 0;

            getSum(n, NoOfNodes, sum);

            int avg = sum / NoOfNodes;

            if (avg == n->val) {
                cnt++;
            }
        }

        return cnt;
    }
};