struct Node {
    int val;
    Node* next;
    Node* prev;
};

class MyCircularDeque {
private:
    Node* head;
    Node* tail;
    vector<int> nums;
    int size;

public:
    MyCircularDeque(int k) {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        size = k;
    }

    bool insertFront(int value) {
        if (nums.size() == size) {
            return false;
        }

        Node* node = new Node(value);
        Node* currnext = head->next;
        head->next = node;
        node->prev = head;
        node->next = currnext;
        currnext->prev = node;

        nums.push_back(value);
       
        return true;
    }

    bool insertLast(int value) {
        if (nums.size() == size)
            return false;

        Node* node = new Node(value);
        Node* prevtail = tail->prev;
        prevtail->next = node;
        node->prev = prevtail;
        node->next = tail;
        tail->prev = node;
        nums.push_back(value);
       
        return true;
    }

    bool deleteFront() {
        if (nums.empty())
            return false;
        Node* toDelete = head->next;

        head->next = toDelete->next;
        toDelete->next->prev = head;
        delete toDelete;
        nums.erase(nums.begin());
       
        return true;
    }

    bool deleteLast() {
        if (nums.empty())
            return false;

        Node* toDelete = tail->prev;

        tail->prev = toDelete->prev;
        toDelete->prev->next = tail;
        delete toDelete;
        nums.pop_back();
       
        return true;
    }

    int getFront() {
        if (nums.empty())
            return -1;

        return head->next->val;
    }

    int getRear() {
        if (nums.empty())
            return -1;

        return tail->prev->val;
    }

    bool isEmpty() { return nums.empty(); }

    bool isFull() { return nums.size() == size; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */