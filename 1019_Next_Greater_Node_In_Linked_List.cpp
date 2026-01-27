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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;

        ListNode* current = head;

        while (current != nullptr) {
            ListNode* temp = current->next;
            int nextGreater = 0;

            while (temp != nullptr) {
                if (temp->val > current->val) {
                    nextGreater = temp->val;
                    break;  
                }
                temp = temp->next;
            }

            ans.push_back(nextGreater);
            current = current->next;
        }

        return ans;
    }
};
