class MyStack {
private:
    queue<int> qt;

    int size;

public:
    MyStack() { size = 0; }

    void push(int x) {
        int s = size;
        qt.push(x);
        size++;

        for (int i = 0; i < s; i++) {
            qt.push(qt.front());
            qt.pop();
        }
    }

    int pop() { 
       int el = qt.front();
       qt.pop();
       size--;
       return el;
    }

    int top() { return qt.front(); }

    bool empty() {
        if (qt.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */