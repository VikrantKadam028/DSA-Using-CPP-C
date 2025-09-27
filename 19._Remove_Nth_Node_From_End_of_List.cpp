/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL)
        return head;

    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    int length = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    int pos = length - n + 1;
    int count = 1;
    if (pos == 1) {
        head = current->next;
        free(current);
        current = NULL;
    } else {
        while (count < pos) {
            prev = current;
            current = current->next;
            count++;
        }
        prev->next = current->next;
        free(current);
        current = NULL;
    }
    return head;
}
