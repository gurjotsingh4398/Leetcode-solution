// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *t1=head,*t2=head;
        for(int i=0;i<n;i++) {
            t2=t2->next;
        }
        while(t2!=NULL && t2->next!=NULL) {
            t1=t1->next;
            t2=t2->next;
        }
        if(t1 == head && t2==NULL) {
            head=head->next;
        } else {
            t1->next=t1->next->next;
        }
        return head;
    }
};