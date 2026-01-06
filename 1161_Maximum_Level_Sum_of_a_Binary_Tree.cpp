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
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> levels;
        // int total = 0;
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);

                level.push_back(node->val);
            }
            levels.push_back(level);
        }

        int maxLevel = 1;
        int maxSum = INT_MIN;

        for (int i = 0; i < levels.size(); i++) {
            int currSum = 0;

            for (int val : levels[i]) {
                currSum += val;
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                maxLevel = i + 1; // 1-based index
            }
        }
    return maxLevel;
    }
};
