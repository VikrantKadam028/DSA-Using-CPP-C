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
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        int key, j;

        for (int i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* temp = head;
        vector<int> result;

        while (temp != nullptr) {
            result.push_back(temp->val);
            temp = temp->next;
        }

        insertionSort(result);
        int n = result.size();

        temp = head;
        for (int i = 0; i < n; i++) {
            temp->val = result[i];
            temp = temp->next;
        }
        return head;
    }
};
