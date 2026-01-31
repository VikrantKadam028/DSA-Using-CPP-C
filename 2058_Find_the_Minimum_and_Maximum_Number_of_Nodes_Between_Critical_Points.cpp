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
    int getlen(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (getlen(head) <= 2) {
            return {-1, -1};
        }

        vector<int> result;

        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* after = curr->next;

        int count = 1;

        while (after != nullptr) {
            // local minima
            if (prev->val > curr->val && curr->val < after->val) {
                result.push_back(count);
            }
            // local maxima
            else if (prev->val < curr->val && curr->val > after->val) {
                result.push_back(count);
            }

            count++;
            prev = curr;
            curr = after;
            after = after->next;
        }

        if (result.size() < 2) {
            return {-1, -1};
        }

        sort(result.begin(), result.end());

        int minDist = INT_MAX;
        for (int i = 1; i < result.size(); i++) {
            minDist = min(minDist, result[i] - result[i - 1]);
        }

        int maxDist = result.back() - result.front();

        return {minDist, maxDist};
    }
};
