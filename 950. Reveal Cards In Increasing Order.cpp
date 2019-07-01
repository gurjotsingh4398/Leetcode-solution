// https://leetcode.com/problems/reveal-cards-in-increasing-order/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        if(n<2) return deck;
        sort(deck.begin(),deck.end(),greater<int>());
        vector<int> ans;
        deque <int> d;
        for(int i=0;i<n;i++) {
            d.push_front(deck[i]);
            if(i!=n-1) {
                int b = d.back();
                d.pop_back();
                d.push_front(b);
            }
        }
        for(int i=0;i<n;i++) {
            ans.push_back(d.front());
            d.pop_front();
        }
        return ans;
    }
};