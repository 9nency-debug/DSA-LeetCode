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
    ListNode* getmiddle(ListNode* head) {
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while(fastptr!= NULL && fastptr->next!= NULL) {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }
        return slowptr;
    }
    int pairSum(ListNode* head) {
        ListNode* temp = getmiddle(head);
        ListNode* first = head;
        ListNode* prev = nullptr;
        int result = 0;
        while(temp != nullptr) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode; 
        }
        while(prev != NULL) {
            result = max(result, first->val + prev->val);
            first = first->next;
            prev = prev->next;
        }
        return result;
    }
};