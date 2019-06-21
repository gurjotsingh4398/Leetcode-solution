// https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode left(0);
        ListNode right(0);
        ListNode *l=&left,*r=&right,*curr=head;
        while(curr){
            if(curr->val<x) {
                l->next=curr;
                l=l->next;
            } else {
                r->next=curr;
                r=r->next;
            }
          curr=curr->next;  
        }
        r->next=NULL;
        l->next=right.next;
        return left.next;
    }
};