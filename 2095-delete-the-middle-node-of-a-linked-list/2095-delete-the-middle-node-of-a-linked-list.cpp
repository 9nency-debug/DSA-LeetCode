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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next ==nullptr) return nullptr;
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            n += 1;
            temp = temp->next;
        }
        int idx = n/2;
        temp = head;
        for(int i = 1; i < idx; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};