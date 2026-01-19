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
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftHead = nullptr;
        ListNode* leftTail = nullptr;
        ListNode* rightHead = nullptr;
        ListNode* rightTail = nullptr;

        ListNode* temp = head;
        while (temp != nullptr) {
            ListNode* nextNN = temp->next;
            temp->next = nullptr;

            if (temp->val < x) {
                if (leftHead == nullptr) {
                    leftHead = leftTail = temp;
                } else {
                    leftTail->next = temp;
                    leftTail = temp;
                }
            } else if (temp->val >= x) {
                if (rightHead == nullptr) {
                    rightHead = rightTail = temp;
                } else {
                    rightTail->next = temp;
                    rightTail = temp;
                }
            }
            temp = nextNN;
        }

        if (leftTail != nullptr) {
            leftTail->next = rightHead;
            return leftHead;
        }
        return rightHead;
    }
};
