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
    ListNode* BuildList(vector<int>& values) {
        ListNode dummy(0);       
        ListNode* current = &dummy; 

        for (int val : values) {
            current->next = new ListNode(val);
            current = current->next;
        }
        return dummy.next; 
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        //push the values of head into vector
        vector<int> headData;
        ListNode* current = head;
        while (current != NULL) {
            headData.push_back(current->val);
            current = current->next;
        }

        //then delete the values of nums into head
        unordered_set<int> removeSet(nums.begin(), nums.end());
        vector<int> filtered;
        for (int val : headData) {
            if (removeSet.find(val) == removeSet.end()) {
                filtered.push_back(val);
            }
        }

        // rebuild the listnode with new head data
        ListNode* newHead = BuildList(filtered);
        return newHead;
    }
};
