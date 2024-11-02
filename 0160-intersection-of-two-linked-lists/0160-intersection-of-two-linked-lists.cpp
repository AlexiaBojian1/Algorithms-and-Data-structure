/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* trevA = headA;
        ListNode* trevB = headB;
        while(trevA != trevB) {
            trevA = (trevA != nullptr) ? trevA=trevA->next : headB;
            trevB = (trevB != nullptr) ? trevB=trevB->next : headA;

        }
        return trevA;
    }
};