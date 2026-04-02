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

    vector<int> getHeadToVec(ListNode* head) {
        ListNode* temp = head;
        vector<int> result;

        while (temp != nullptr) {
            result.push_back(temp->val);
            temp = temp->next;
        }
        return result;
    }

    ListNode* createNode(int data) { 
        return new ListNode(data); 
    }

    void appendAtEnd(ListNode* NN) {
        if (head2 == nullptr) {
            head2 = tail = NN;
            return; 
        }
        tail->next = NN;
        tail = NN;
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> nums = getHeadToVec(head);
        head2 = tail = nullptr;

        bool found = true;

        while (found) {
            found = false;

            for (int i = 0; i < nums.size(); i++) {
                int sum = 0;

                for (int j = i; j < nums.size(); j++) {
                    sum += nums[j];

                    if (sum == 0) {
                        nums.erase(nums.begin() + i, nums.begin() + j + 1);
                        found = true;
                        break; 
                    }
                }

                if (found) break;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            appendAtEnd(createNode(nums[i]));
        }

        return head2;
    }
};