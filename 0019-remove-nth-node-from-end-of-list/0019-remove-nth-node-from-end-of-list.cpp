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
         ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move fast ahead by 'n+1' steps to maintain a gap of 'n' between slow and fast
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both slow and fast until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Skip the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Clean up the deleted node to avoid memory leaks
        delete nodeToDelete;
        
        // Get the new head of the list
        ListNode* newHead = dummy->next;
        delete dummy;  // Clean up the dummy node
        return newHead;
    }
};