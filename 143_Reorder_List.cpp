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
    void reorderList(ListNode* head) {
        if (head == nullptr)
            return;
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the 2nd half
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* current = slow->next;
        slow->next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        ListNode* first = head;
        ListNode* second = prev;

        // merge both alternately
        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
    }
};

// BRUTE - FORCE (TC - O(n), SC - O(n))
//  class Solution {
//  public:
//      void reorderList(ListNode* head) {
//          ListNode* temp = head;
//          vector<int> result;

//         while (temp != nullptr) {
//             result.push_back(temp->val);
//             temp = temp->next;
//         }

//         int L0 = 0;
//         int Ln = result.size() - 1;

//         vector<int> main;
//         while (L0 <= Ln) {
//             main.push_back(result[L0]);
//             main.push_back(result[Ln]);
//             L0++;
//             Ln--;
//         }

//         int i = 0;
//         temp = head;

//         while (temp) {
//             temp->val = main[i];
//             i++;
//             temp = temp->next;
//         }
//     }
// };
