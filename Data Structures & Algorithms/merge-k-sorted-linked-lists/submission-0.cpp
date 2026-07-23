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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        ListNode* result=NULL;
        if(lists.size()>2){
            vector<ListNode*> subList(lists.begin()+1, lists.end());
            result = mergeKLists(subList);
            lists.erase(lists.begin()+1, lists.end());
            lists[1] = result;
        }
        result = NULL;
        ListNode* current = result;
        ListNode* l=lists[0];
        ListNode* r=lists[1];
        while(l!=NULL && r!=NULL){
            if(l->val<r->val){
                if(result==NULL){
                    current = l;
                    result = current;
                }
                else {
                    current->next = l;
                    current = current->next;
                }
                l = l->next;
            }
            else{
                if(result==NULL){
                    current = r;
                    result = current;
                }
                else {
                    current->next = r;
                    current = current->next;
                }
                r = r->next;
            }
        }
        if(l==NULL && result!=NULL) current->next = r;
        if(r==NULL && result!=NULL) current->next = l;
        return result;       
    }
};
