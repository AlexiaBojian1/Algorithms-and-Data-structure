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
    ListNode* removeElements(ListNode* head, int val) {

       ListNode* sentinel = new ListNode(0);
       sentinel->next = head;
       ListNode* prev = sentinel;
       ListNode* curr = head;
       ListNode* todelete = nullptr;

        while(curr != nullptr) {
            if(curr->val == val) {
                prev->next = curr->next;
                todelete = curr;
            } else {
                prev = curr;
            }
            curr = curr->next;
            if(todelete != nullptr) {
                delete todelete;
                todelete = nullptr;
            }
        }
        ListNode* ret = sentinel->next;
        delete sentinel;
        return ret;
    }
};