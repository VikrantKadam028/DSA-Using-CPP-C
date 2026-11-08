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
    pair<ListNode*, int> reverseLL(ListNode*& l1) {
        ListNode* prev = nullptr;
        ListNode* curr = l1;
        ListNode* next = nullptr;
        int len = 0;

        while (curr != nullptr) {
            len++;
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        l1 = prev;
        return {l1, len};
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto t1 = reverseLL(l1);
        auto t2 = reverseLL(l2);

        int lenl1 = t1.second;
        int lenl2 = t2.second;

        ListNode* head = nullptr;
        bool isl1used = false;

        if (lenl1 > lenl2) {
            head = t1.first;
            isl1used = true;
        } else {
            head = t2.first;
            isl1used = false;
        }

        ListNode* temp = nullptr;
        if (isl1used) {
            temp = t2.first;
        } else {
            temp = t1.first;
        }

        ListNode* head2 = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while (head != nullptr) {
            int sum = 0;

            if (head != nullptr && temp != nullptr) {
                sum = head->val + temp->val;
                if (carry > 0) {
                    sum += carry;
                }

                if (to_string(sum).length() > 1 && sum > 9) {
                    string str = to_string(sum);
                    carry = str[0] - '0';
                    sum = str[1] - '0';

                } else if (sum < 10) {
                    carry = 0;
                }

                ListNode* newNode = new ListNode(sum);
                if (head2 == nullptr) {
                    head2 = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            } else if (head != nullptr && temp == nullptr) {
                sum = head->val + carry;

                carry = sum / 10;
                sum = sum % 10;

                ListNode* newNode = new ListNode(sum);

                if (head2 == nullptr) {
                    head2 = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
            head = head->next;
            if (temp != nullptr) {
                temp = temp->next;
            }
        }

        if (carry > 0) {
            tail->next = new ListNode(carry);
        }

        auto it3 = reverseLL(head2);
        return it3.first;
    }
};