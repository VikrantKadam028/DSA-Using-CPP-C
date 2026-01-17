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

    void AppendAtEnd(ListNode* NN) {
        if (head2 == nullptr) {
            head2 = tail = NN;
            return;
        }

        tail->next = NN;
        tail = NN;
    }

    vector<int> getData(ListNode* head) {
        ListNode* temp = head;
        vector<int> result;

        while (temp != nullptr) {
            result.push_back(temp->val);
            temp = temp->next;
        }
        return result;
    }

    ListNode* createNode(int data) { return new ListNode(data); }

    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        head2 = tail = nullptr;

        // get LL -> vector(result)
        vector<int> result = getData(head);

        // reverse the vector
        reverse(result.begin(), result.end());
        st.push(result[0]);

        // check if result[i] > st.top() -> push
        for (int i = 1; i < result.size(); i++) {
            if (result[i] < st.top()) {
                continue;
            } else {
                st.push(result[i]);
            }
        }

        // convert back stack -> LL
        while (!st.empty()) {
            int elem = st.top();
            st.pop();

            ListNode* NN = createNode(elem);
            AppendAtEnd(NN);
        }
        return head2;
    }
};
