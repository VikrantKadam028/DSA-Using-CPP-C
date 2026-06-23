struct Node {
    int val;
    int minSoFar;
    Node* next;
};

class MinStack {
private:
    Node* topNode;
    int size;

public:
    MinStack() {
        topNode = nullptr;
        size = 0;
    }

    void push(int value) {
        Node* temp = new Node;
        temp->val = value;

        if (topNode == nullptr) {
            temp->minSoFar = value;
        } else {
            temp->minSoFar = min(value, topNode->minSoFar);
        }

        temp->next = topNode;
        topNode = temp;
        size++;
    }

    void pop() {
        if (topNode == nullptr)
            return;

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;

        size--;
    }

    int top() {
        return topNode->val;
    }

    int getMin() {
        return topNode->minSoFar;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */