class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int len1 = 0, len2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1) {
            len1++;
            temp1 = temp1->next;
        }
        while (temp2) {
            len2++;
            temp2 = temp2->next;
        }

        int diff = abs(len1 - len2);

        temp1 = headA;
        temp2 = headB;

        // move only the longer list
        if (len1 > len2) {
            while (diff--) temp1 = temp1->next;
        } else {
            while (diff--) temp2 = temp2->next;
        }

        // move together
        while (temp1 && temp2) {
            if (temp1 == temp2)
                return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return nullptr;
    }
};
