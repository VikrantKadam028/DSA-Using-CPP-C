/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = createNode(0);
    struct ListNode* tracker = dummy;

    struct ListNode* l1temp = l1;
    struct ListNode* l2temp = l2;

    int carry = 0;

    while (l1temp != NULL || l2temp != NULL) {
        int n1 = (l1temp != NULL) ? l1temp->val : 0;
        int n2 = (l2temp != NULL) ? l2temp->val : 0;

        int sum = n1 + n2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        struct ListNode* newNode = createNode(sum);

        tracker->next = newNode;
        tracker = newNode;

        if (l1temp != NULL)
            l1temp = l1temp->next;
        if (l2temp != NULL)
            l2temp = l2temp->next;
    }

    if (carry > 0) {
        tracker->next = createNode(carry);
    }

    return dummy->next;
}
