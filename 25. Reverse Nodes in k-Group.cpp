// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *curr=head, *nxt=NULL, *prev=NULL;
        int size=0;
        while(curr) {
            curr=curr->next;
            size++;
        }
        if(size<k) {
            return head;
        }
        curr=head;
        int count= 0;
        while(curr && count<k) {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            count++;
        }
        if(nxt) {
            head->next=reverseKGroup(nxt,k);
        }
        return prev;
    }
};