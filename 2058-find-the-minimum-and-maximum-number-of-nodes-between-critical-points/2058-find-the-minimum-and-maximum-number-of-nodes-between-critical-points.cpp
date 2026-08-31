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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int min_Dist = INT_MAX;
        int max_Dist = -1;
        int i = 1;
        int first = 0;
        int prev = 0;
        while (head != nullptr && head->next != nullptr && head->next->next != nullptr) {
            ListNode* curr = head->next;
            ListNode* next = head->next->next;
            if (curr != nullptr) {
                if ((curr->val > head->val && curr->val > next->val) || (curr->val < head->val && curr->val < next->val)) 
                {
                    if (first == 0) first = i;
                    else {
                        min_Dist = min(min_Dist, i - prev);
                        max_Dist = i - first;
                    }
                    prev = i;
                }
            }
            i++;
            head = head->next;
        }
        if (min_Dist == INT_MAX) min_Dist = -1;
        return {min_Dist, max_Dist};
    }
};