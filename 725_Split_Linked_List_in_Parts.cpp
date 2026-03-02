class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<vector<ListNode*>> v;
        vector<ListNode*> result;

        // Step 1: Find length
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        int baseSize = length / k;
        int extra = length % k;

        temp = head;

        // Step 2: Create k parts
        for (int i = 0; i < k; i++) {

            vector<ListNode*> part;

            int currentSize = baseSize + (extra > 0 ? 1 : 0);
            if (extra > 0) extra--;

            for (int j = 0; j < currentSize && temp != nullptr; j++) {
                part.push_back(temp);
                temp = temp->next;
            }

            v.push_back(part);
        }

        // Step 3: Convert to result and break links
        for (int i = 0; i < k; i++) {

            if (v[i].empty()) {
                result.push_back(nullptr);
            } else {
                result.push_back(v[i][0]);
                v[i].back()->next = nullptr;   // break the chain
            }
        }

        return result;
    }
};
