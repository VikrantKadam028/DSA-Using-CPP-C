/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        if (head == nullptr)
            return head;
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;

        //Apply Floyd’s Cycle Detection 2 times
        // 1. to detect the cycle
        // 2. find cycle start

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            //confirmed that cycle exist
            if (slow == fast) {
                slow = head;

                //find the starting point node
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
       return nullptr; 
    }
};
