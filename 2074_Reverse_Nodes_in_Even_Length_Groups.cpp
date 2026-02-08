class Solution {
public:
    ListNode* reverseLLGroup(ListNode* head, int length) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (length-- && current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    int getLen(ListNode* head) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int groups = 1;
        int totalLen = getLen(head);

        if (totalLen <= 2) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* temp = head;

        while (temp != nullptr && totalLen > 0) {
            int useSize = min(groups, totalLen);

            ListNode* end = temp;
            for (int i = 0; i < useSize; i++) {
                if (end != nullptr)
                    end = end->next;
            }

            if (useSize % 2 == 0) {
                ListNode* groupStart = temp;
                ListNode* rev = reverseLLGroup(temp, useSize);

                prev->next = rev;
                groupStart->next = end;

                prev = groupStart;
                temp = end;
            } else {
                for (int i = 0; i < useSize; i++) {
                    prev = temp;
                    temp = temp->next;
                }
            }

            totalLen -= useSize;
            groups++;
        }

        return dummy.next;
    }
};
