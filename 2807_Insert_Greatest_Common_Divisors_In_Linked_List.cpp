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
    int Getgcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    ListNode* createNode(int data) { return new ListNode(data); }

    void appendAtEnd(ListNode* NN) {
        if (head2 == nullptr) {
            head2 = tail = NN;
            return;
        }
        tail->next = NN;
        tail = NN;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int> nums = getHeadToVec(head);
        vector<int> result;
        head2 = tail = nullptr;

        for (int i = 0; i < nums.size() - 1; i++) {
            int gcdNo = Getgcd(nums[i], nums[i + 1]);
            result.push_back(nums[i]);
            result.push_back(gcdNo);
        }

        result.push_back(nums.back());

        for (int i = 0; i < result.size(); i++) {
            appendAtEnd(createNode(result[i]));
        }

        return head2;
    }
};