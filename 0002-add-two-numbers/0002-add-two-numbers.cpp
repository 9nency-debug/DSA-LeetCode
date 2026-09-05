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

    ListNode* solve(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == nullptr && l2 == nullptr && carry == 0) {
            return nullptr;
        }
        int sum = carry;
        if (l1 != nullptr) sum += l1->val;
        if (l2 != nullptr) sum += l2->val;
        ListNode* node = new ListNode(sum % 10);
        carry = sum / 10;
        ListNode* next1 = (l1 != nullptr) ? l1->next : nullptr;
        ListNode* next2 = (l2 != nullptr) ? l2->next : nullptr;
        node->next = solve(next1, next2, carry);
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2, 0);
    }
};