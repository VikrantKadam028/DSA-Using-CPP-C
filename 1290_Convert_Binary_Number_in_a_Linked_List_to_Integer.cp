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
    int getDecimalValue(ListNode* head) {
        string result = "";
        ListNode* temp = head;

        while (temp != NULL) {
            result += to_string(temp->val);
            temp = temp->next;
        }
        int decimal = stoi(result, 0, 2);
        return decimal;
    }
};
