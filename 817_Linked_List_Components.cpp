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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* temp = head;
        int count = 0;

        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
        }

        while (temp) {
            if (mp[temp->val] == 1) {
                count++;

                while (temp && mp[temp->val] == 1) {
                    temp = temp->next;
                }
            } else {
                temp = temp->next;
            }
        }
        return count;
    }
};