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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int size = 0;
        ListNode* current = head;
        while(current != nullptr) {
            current = current ->next;
            size ++;
        }
         int splitsize = size/k;
         int remainingParts = size%k;

         current = head;
         ListNode* prev = head;

         for(int i = 0;i < k;i++) {
            ListNode* newpart = current;
            int currentsize = splitsize;
            if(remainingParts > 0) {
                currentsize++;
                remainingParts--;
            }

            int j = 0;
            while(j < currentsize) {
                prev = current;
                if(current != nullptr) {
                    current = current->next;
                }
                j++;
            }
            if(prev != nullptr) {
                prev->next = nullptr;
            }
            ans[i] = newpart;
         }
         return ans;
    }
};