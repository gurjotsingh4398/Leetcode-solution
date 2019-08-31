// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
        priority_queue<int> g;
        priority_queue<int, vector<int>, greater<int>> s;
        // int median;
    
    void addNum(int num) {
        g.push(num);
        s.push(g.top());
        g.pop();
        
        if(g.size()<s.size()) {
            g.push(s.top());
            s.pop();
        }
     }
    
    double findMedian() {
        if(g.size()>s.size()) return (double)g.top();
        return ((double)(g.top()+s.top()))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */