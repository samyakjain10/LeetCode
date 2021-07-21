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
    
    bool check(ListNode* head, int k){
        
        ListNode* temp = head;
        int count = 1;
        while(temp!=NULL){
            if(count >= k) return true;
            count++;
            temp = temp->next;
        }
        return false;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextptr;
        
        int count = 0;
        
        if(!check(head,k)){
            return head;
        }
        
        while(curr!=NULL && count<k){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
            count++;
        }
        
        if(nextptr!=NULL)
        head->next = reverseKGroup(nextptr,k);
        
        return prev;
        
    }
};