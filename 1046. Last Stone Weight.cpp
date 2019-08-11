// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int size=0;
    
    int parent(int i) {
        return (i-1)/2;
    }
    
    int left(int i) {
        return (2*i)+1;
    }
    
    int right(int i) {
        return (2*i)+2;
    }
    
    void heapify(vector<int> &h, int i) {
        int l=left(i);
        int r=right(i);
        int largest=i;
        if(l<size && h[largest]<h[l]) largest=l;
        if(r<size && h[largest]<h[r]) largest=r;
        if(largest!=i) {
            swap(h[largest], h[i]);
            heapify(h, largest);
        }
    }
    
    int extractMax(vector<int> &h) {
        int max=h[0];
        h[0]=h[size-1];
        size--;
        heapify(h, 0);
        return max;
    }
    
    int lastStoneWeight(vector<int>& stones) {
        size = stones.size();
        int j = (size-1)/2; 
        while(j >= 0)  { 
            heapify(stones, j); 
            j--; 
        } 
        while(size>1) {
            int a=extractMax(stones);
            int b=extractMax(stones);
            int diff=a-b;
            if(diff>0) {
                stones[size]=diff;
                size++;
                int i=size-1;
                while (i != 0 && stones[parent(i)]<stones[i]) { 
                   swap(stones[i], stones[parent(i)]); 
                   i = parent(i); 
                } 
            }
        }
        cout<<size;
        return size==0 ? 0 : stones[0];
    }
};