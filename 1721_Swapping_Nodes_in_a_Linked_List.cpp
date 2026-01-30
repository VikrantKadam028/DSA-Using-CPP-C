class Solution {
public:
    ListNode* head2 = nullptr;
    ListNode* tail = nullptr;

    ListNode* createNode(int data) {
        return new ListNode(data);
    }

    void AppendLast(ListNode* NN) {
        if (head2 == nullptr) {
            head2 = tail = NN;
            return;
        }
        tail->next = NN;
        tail = NN;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        head2 = nullptr;
        tail = nullptr;

        vector<int> result;
        ListNode* temp = head;

        while (temp != nullptr) {
            result.push_back(temp->val);
            temp = temp->next;
        }

        int n = result.size();
        int tempVal = result[k - 1];
        result[k - 1] = result[n - k];
        result[n - k] = tempVal;

        for (int i = 0; i < n; i++) {
            AppendLast(createNode(result[i]));
        }

        return head2;
    }
};
