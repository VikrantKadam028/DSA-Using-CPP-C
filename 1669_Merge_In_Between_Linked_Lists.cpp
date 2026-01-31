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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tempA = list1;
        ListNode* tempB = list1;

        while (a != 1) {
            tempA = tempA->next;
            a--;
        }

        while (b != 0) {
            tempB = tempB->next;
            b--;
        }
        tempB = tempB->next;

        tempA->next = list2;

        ListNode* tempC = list2;
        while (tempC->next != nullptr) {
            tempC = tempC->next;
        }
        tempC->next = tempB;

        return list1;
    }
};
