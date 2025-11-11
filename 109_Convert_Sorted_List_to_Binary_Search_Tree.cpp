/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* helper(vector<int>& v, int start, int end) {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = helper(v, start, mid - 1);
        root->right = helper(v, mid + 1, end);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> array;
        ListNode* temp = head;
        while (temp != nullptr) {
            array.push_back(temp->val);
            temp = temp->next;
        }
        return helper(array, 0, array.size() - 1);
    }
};
