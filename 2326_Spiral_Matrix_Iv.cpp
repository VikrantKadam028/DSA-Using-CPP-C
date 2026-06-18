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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n));

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

       

        vector<int> nums;
        ListNode* temp = head;
        int len = 0;
        int idx = 0;
        while (temp != nullptr) {
            nums.push_back(temp->val);
            len++;
            temp = temp->next;
        }

         int diff = (m * n) - len;

        for (int i = 0; i < diff; i++) {
            nums.push_back(-1);
        }

        while (left <= right && top <= bottom) {

            // L to R
            for (int i = left; i <= right; i++) {
                ans[top][i] = nums[idx++];
            }
            top++;

            // Top-> Bottom
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = nums[idx++];
            }
            right--;

            // Right -> Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i] = nums[idx++];
                }
            }
            bottom--;

            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = nums[idx++];
                }
            }
            left++;
        }

        return ans;
    }
};