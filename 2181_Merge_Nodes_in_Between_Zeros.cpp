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

    void AppendAtLast(ListNode* NN) {
        if (head2 == nullptr) {
            head2 = NN;
            tail = NN;
            return;
        }

        tail->next = NN;
        tail = NN;
    }
    ListNode* mergeNodes(ListNode* head) {
        ListNode* first = head;
        vector<int> num;
        vector<int> result;
        int sum = 0;
        head2 = tail = nullptr;

        ListNode* second = head->next;
        while (second != nullptr) {
            while (second->val != 0) {
                sum += second->val;
                second = second->next;
            }

            if (first->val == 0 && second->val == 0) {
                result.push_back(sum);
                sum = 0;
                first = second;
                second = second->next;
            }
        }

        for (int i = 0; i < result.size(); i++) {
            AppendAtLast(createNode(result[i]));
        }
        return head2;
    }
};
