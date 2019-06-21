// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *curr=head, *prev;
        ListNode dummy(0);
        prev=&dummy;
        
        bool flag=true;
        if(head->val==head->next->val) flag=false;
        
        while(curr && curr->next) {
            if(curr->val!=curr->next->val) {
                prev=curr;
                curr=curr->next;
            } else {
                int num=curr->val;
                while(curr && curr->val==num) {
                    curr=curr->next;
                }
                prev->next=curr;
            }
        }
        
        if(flag) return head;
        return dummy.next;
    }
};