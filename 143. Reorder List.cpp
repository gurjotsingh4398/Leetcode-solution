// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        if(head==NULL) return;
        ListNode *prev=head, *temp=head;
        while(temp != NULL && temp->next != NULL ) {
            prev=prev->next;
            temp=temp->next->next;
        }
        ListNode *curr=prev->next, *nxt, *temp2;
        temp2=prev;
        while(curr) {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        temp2->next=NULL; // next of mid node to NULL to get stopping condition.
        curr=head; //curr at start and prev points at the last node.
        ListNode * nxt2;

        while(curr->next != prev && curr != prev) {
            nxt=curr->next;
            nxt2=prev->next;
            curr->next=prev;
            prev->next=nxt;
            curr=nxt;
            prev=nxt2;
        }
    }
};