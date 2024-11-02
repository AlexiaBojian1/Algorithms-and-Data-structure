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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode * cur =head;
        ListNode * prev = nullptr;
        while(left > 1) {
            prev = cur ;
            cur = cur->next;
            left--;
            right--;
        }
        ListNode * con = prev;
        ListNode * tail = cur;
        ListNode * third = nullptr;
        while(right > 0) {
            third = cur->next;
            cur->next = prev;
            prev = cur;
            cur  = third;
            right --;
        }
        
        if (con!= nullptr) {
            con->next = prev;
        } else {
            head = prev;
        }
        tail->next = cur;
        return head;
    }
};