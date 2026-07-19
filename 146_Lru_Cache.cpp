struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
};

class LRUCache {
private:
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;
    int capacity;

public:
    LRUCache(int capacity_) {
        capacity = capacity_;
        mpp.clear();
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* prevcurr = node->prev;
        Node* after = node->next;

        prevcurr->next = after;
        after->prev = prevcurr;
    }

    void InsertAfterHead(Node* node) {
        Node* after = head->next;

        head->next = node;
        node->prev = head;

        node->next = after;
        after->prev = node;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node* node = mpp[key];
        deleteNode(node);
        InsertAfterHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            InsertAfterHead(node);
        } else {
            if (mpp.size() == capacity) {
                Node* node = tail->prev;
                deleteNode(node);
                mpp.erase(node->key);
                delete node;
            }

            Node* node = new Node(key, value);
            mpp[key] = node;
            InsertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */