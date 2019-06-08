// https://leetcode.com/problems/copy-list-with-random-pointer/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* curr = head;
        unordered_map<Node*, Node*> m;
        while(curr) {
            Node* t = new Node(curr->val);
            m[curr] = t;
            curr = curr->next;
        }
        curr = head;
        while(curr) {
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        return m[head];
    }
};