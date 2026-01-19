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
    ListNode* head2 = nullptr;
    ListNode* tail = nullptr;

    ListNode* createNode(int data) { return new ListNode(data); }

    void AppendAtEnd(ListNode* NN) {
        if (head2 == nullptr) {
            head2 = tail = NN;
            return;
        }

        tail->next = NN;
        tail = NN;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        vector<int> result;

        head2 = tail = nullptr;

        while (temp != nullptr) {
            result.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = 0; i + k <= result.size(); i += k) {
            int left = i;
            int right = i + k - 1;

            while (left < right) {
                swap(result[left], result[right]);
                left++;
                right--;
            }
        }

        // vector -> LL
        for (int i = 0; i < result.size(); i++) {
            AppendAtEnd(createNode(result[i]));
        }

        return head2;
    }
};
