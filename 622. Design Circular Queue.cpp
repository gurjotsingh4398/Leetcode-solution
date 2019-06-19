// https://leetcode.com/problems/design-circular-queue/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class MyCircularQueue {
public:
    vector<int> q;
    int f,e,l;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q=vector<int>(k,0);
        f=e=0;
        l=k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        q[e%l]=value;
        e++;
        // e=e%l;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        f++;
        // f=f%l;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return q[f%l];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return q[(e-1)%l];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (e==f);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (e-f==l);
    }
};

/**e-f
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */