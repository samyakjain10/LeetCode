
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        
        // Find middle & reverse 2nd half of the list
        ListNode* reversed2ndHalf = reverseList(findMiddle(head));
        
        // Verify palindrome property
        while (reversed2ndHalf != nullptr && head)
        {
            if (reversed2ndHalf->val != head->val)
                return false;
            
            reversed2ndHalf = reversed2ndHalf->next;
            head = head->next;
        }
        
        return true;
    }
    
private:
    ListNode* findMiddle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* slow = head; ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If we have an odd number of elements skip over the middle element
        if (fast != nullptr) slow = slow->next;
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* prev = nullptr;
        while (head != nullptr)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};