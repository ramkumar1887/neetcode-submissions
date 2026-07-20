/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total=0;
        ListNode* current=head;
        while(current!=NULL){
            total++;
            current = current->next;
        }

        current = head;
        for(int i=0;i<total-n-1;i++){
            current = current->next;
        }
        if(total-n==0) return head->next;
        current->next = current->next->next;
        return head;
    }
};
