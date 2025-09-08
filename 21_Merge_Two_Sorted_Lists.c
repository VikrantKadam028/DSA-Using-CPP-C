/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;

    struct ListNode* i;
    struct ListNode* j;
    int tempData;
    for (i = list1; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->val > j->val) {
                tempData = i->val;
                i->val = j->val;
                j->val = tempData;
            }
        }
    }

    return list1;
}

