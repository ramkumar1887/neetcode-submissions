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
    void reorderList(ListNode* head) {
        ListNode *current=head, *last=nullptr, *lastSec=nullptr;
        while(current->next!=NULL && current->next->next!=NULL){
            //current = current->next;
            lastSec = current;
            while(lastSec->next->next!=NULL) lastSec = lastSec->next;
            last = lastSec->next;
            last->next = current->next;
            current->next = last;
            lastSec->next = NULL;
            current = last->next;
        }
        //return head;
    }
};
