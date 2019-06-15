// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> stk1,stk2;
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stk2.empty()) {
            while(!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int tmp=stk2.top();
        stk2.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        if(stk2.empty()) {
            while(!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(stk1.empty() && stk2.empty()) return true;
        return false;
    }
};
