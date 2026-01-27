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
    ListNode* doubleIt(ListNode* head) {
        vector<int> result;
        int carry = 0;

        ListNode* temp = head;
        vector<int> digits;
        while (temp) {
            digits.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = digits.size() - 1; i >= 0; i--) {
            int val = digits[i] * 2 + carry;
            result.push_back(val % 10);
            carry = val / 10;
        }

        if (carry)
            result.push_back(carry);

        reverse(result.begin(), result.end());

        head2 = tail = nullptr;
        for (int d : result) {
            AppendAtEnd(createNode(d));
        }

        return head2;
    }
};
