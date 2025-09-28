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
    bool isPalindrome(ListNode* head) {
        vector<int> result;
        ListNode* temp = head;

        while (temp != NULL) {
            result.push_back(temp->val);
            temp = temp->next;
        }

        int n = result.size();
        for (int i = 0; i < n; i++) {
            if (result[i] != result[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
