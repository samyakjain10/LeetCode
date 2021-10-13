 ListNode* reverseList(ListNode* head) {        
        ListNode *prev=NULL,*curr=head,*newcurr;
        while(curr)
        {
            newcurr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newcurr;
        }
        return prev;
        
    }
