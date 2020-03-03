// Time  : 24 ms (99.30%)
// Memory: 16.6 MB (7.33%)

class MyCircularQueue {
private:
    vector<int> que;
    // if use int* should override opeartor=(const MyCircularQueue&)
    // and MyCircularQueue(const MyCircularQueue&)
    int front, rear, size, capacity;
    mutex queMutex;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        que.resize(k);
        capacity = k;
        front = size = 0;
        rear = -1;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        lock_guard<mutex> guard(queMutex);
        if (size == capacity) return false;
        rear = (rear + 1) % capacity;
        que[rear] = value;
        ++size;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        lock_guard<mutex> guard(queMutex);
        if (size == 0) return false;
        front = (front + 1) % capacity;
        --size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        lock_guard<mutex> guard(queMutex);
        return size ? que[front] : -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        lock_guard<mutex> guard(queMutex);
        return size ? que[rear] : -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        lock_guard<mutex> guard(queMutex);
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        lock_guard<mutex> guard(queMutex);
        return size == capacity;
    }
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
