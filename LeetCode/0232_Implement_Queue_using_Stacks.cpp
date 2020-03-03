// Time  : 4 ms (67.78%)
// Memory: 9.4 MB (5.01%)

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st[1].push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = peek();
        st[0].pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if (st[0].empty()) pull();
        return st[0].top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st[0].empty() && st[1].empty();
    }

private:
    stack<int> st[2];

    void pull() {
        while (!st[1].empty()) {
            st[0].push(st[1].top());
            st[1].pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
