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
    ListNode* createList(vector<int>& arr) {
        if (arr.empty()) return nullptr;

        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;

        for (int i = 1; i < arr.size(); i++) { 
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> combined;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* node = lists[i];
            while (node != nullptr) {
                combined.push_back(node->val);
                node = node->next;
            }
        }

        if (combined.empty()) return nullptr;

        sort(combined.begin(), combined.end());
        return createList(combined);
    }
};
