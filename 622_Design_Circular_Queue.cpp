struct Node {
    int val;
    Node* next;
    Node* prev;
};

class MyCircularQueue {
private:
    // vector<int> nums;
    int size;
    vector<int> nums;
    Node* head;
    Node* tail;

public:
    MyCircularQueue(int k) {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        size = k;
    }

    bool enQueue(int value) {
        if (nums.size() == size) {
            return false;
        } else {
            Node* node = new Node(value);
            Node* prevtail = tail->prev;
            prevtail->next = node;
            node->next = tail;
            node->prev = prevtail;
            tail->prev = node;
            nums.push_back(node->val);
        }

        return true;
    }

    bool deQueue() {
        if (nums.empty())
            return false;

        Node* nextNode = head->next->next;
        Node* toDelete = head->next;

        head->next = nextNode;
        nextNode->prev = head;
        delete toDelete;
        nums.pop_back();
        return true;
    }

    int Front() {
        if (nums.empty())
            return -1;

        int value = head->next->val;
        return value;
    }

    int Rear() {
        if (nums.empty())
            return -1;

        int value = tail->prev->val;
        return value;
    }

    bool isEmpty() { return nums.empty(); }

    bool isFull() { return nums.size() == size; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */