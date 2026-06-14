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
    int pairSum(ListNode* head) {
        // find length
        ListNode* temp = head;
        int len = 0;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        int breakPoint = len / 2;

        ListNode* end = head;
        int cnt = breakPoint - 1;

        while (cnt--) {
            end = end->next;
        }
        ListNode* start = nullptr;
        start = end->next;

        end->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        end->next = prev;

        // twin sum
        ListNode* l1 = nullptr;
        ListNode* l2 = nullptr;

        l1 = head;
        l2 = prev;

        int maxSum = INT_MIN;
        for (int i = 0; i < breakPoint; i++) {
            int sum = l1->val + l2->val;

            maxSum = max(maxSum, sum);

            l1 = l1->next;
            l2 = l2->next;
        }

        return maxSum;
    }
};