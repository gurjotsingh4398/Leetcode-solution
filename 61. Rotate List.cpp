// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *t1=head,*t2=head;
        int size=1;
        while(t1->next) {
            t1=t1->next;
            size++;
        }
        k=k%size;
        
        if(k==0) return head;
        
        t1=head;
        for(int i=0;i<k;i++) {
            t2=t2->next;
        }
        while(t2->next!=NULL) {
            t1=t1->next;
            t2=t2->next;
        }
        t2->next=head;
        head=t1->next;
        t1->next=NULL;
        return head;
    }
};