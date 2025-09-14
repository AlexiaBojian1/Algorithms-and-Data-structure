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

        struct Comparator {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };

        std::priority_queue<ListNode* , std::vector<ListNode*>, Comparator> pq;
        for(auto list : lists) {
            if(list) {
                 pq.push(list);
            }
        }

        ListNode* head = new ListNode(0);
        ListNode* point = head;
        while(!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            point->next =new ListNode(curr->val);
            point = point->next;
            if(curr -> next) {
                pq.push(curr->next);
            }
        }
        ListNode* RES = head->next;
        delete head;
        return RES;
    }
};