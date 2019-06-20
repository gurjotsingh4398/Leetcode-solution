// https://leetcode.com/problems/swap-nodes-in-pairs/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev=head,*curr=head,*nxt=head->next;
        curr->next=nxt->next;
        nxt->next=curr;
        head=nxt;
        prev=curr;
        curr=curr->next;
        while(curr!=NULL && curr->next!=NULL) {
            nxt=curr->next;
            curr->next=nxt->next;
            nxt->next=curr;
            prev->next=nxt;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};