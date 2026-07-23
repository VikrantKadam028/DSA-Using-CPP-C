struct Node {
    int val;
    Node* next;
    Node* prev;
};

class FrontMiddleBackQueue {
private:
    Node* head;
    Node* tail;
    vector<int> nums;

    int getLength() {
        int len = 0;
        Node* curr = head->next;
        while (curr != tail) {
            len++;
            curr = curr->next;
        }
        return len;
    }

public:
    FrontMiddleBackQueue() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void pushFront(int val) {
        Node* node = new Node(val);
        Node* currnext = head->next;
        head->next = node;
        node->next = currnext;
        node->prev = head;
        currnext->prev = node;
        nums.push_back(val);
    }

    void pushMiddle(int val) {
        int len = getLength();
    
        int middle = len / 2;
        
        Node* curr = head;
        while (middle--) {
            curr = curr->next;
        }
        
        Node* node = new Node(val);
        Node* currnext = curr->next;
        
        curr->next = node;
        node->prev = curr;
        node->next = currnext;
        currnext->prev = node;
        
        nums.push_back(val);
    }

    void pushBack(int val) {
        Node* node = new Node(val);
        Node* prevnext = tail->prev;
        prevnext->next = node;
        node->next = tail;
        node->prev = prevnext;
        tail->prev = node;
        nums.push_back(val);
    }

    int popFront() {
        if (nums.empty())
            return -1;

        Node* toDelete = head->next;
        head->next = toDelete->next;
        toDelete->next->prev = head;
        int val = toDelete->val;
        delete toDelete;
        nums.pop_back(); 
        return val;
    }

    int popMiddle() {
        if (nums.empty())
            return -1;
            
        int len = getLength();
       
        int middle;
        if (len % 2 == 0) {
            middle = len / 2 - 1; 
        } else {
            middle = len / 2;     
        }
        
        Node* curr = head;
        while (middle--) {
            curr = curr->next;
        }
        
        Node* toDelete = curr->next;
        Node* currprev = curr;
        Node* currnext = toDelete->next;
        
        currprev->next = currnext;
        currnext->prev = currprev;
        
        int val = toDelete->val;
        delete toDelete;
        nums.pop_back(); 
        return val;
    }

    int popBack() {
        if (nums.empty())
            return -1;

        Node* toDelete = tail->prev;
        tail->prev = toDelete->prev;
        toDelete->prev->next = tail;
        int val = toDelete->val;
        delete toDelete;
        nums.pop_back();
        return val;
    }
};