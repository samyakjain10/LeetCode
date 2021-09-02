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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* t1 = l1, *t2 = l2;
        
        ListNode* dummy = new ListNode(0);
        
        ListNode* temp = dummy;
        
        while(t1!=NULL && t2!=NULL){
            
            if(t1->val < t2->val){
                temp->next = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
            }
            
            temp = temp->next;
            
        }
        
        while(t1!=NULL){
            temp->next = t1;
            temp = temp->next;
            t1= t1->next;
        }
        
        while(t2!=NULL){
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }
        
        temp->next = NULL;
        return dummy->next;
        
    }
};