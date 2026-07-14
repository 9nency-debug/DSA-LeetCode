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
        if(head==NULL) return NULL;
        ListNode* random=new ListNode(0);
        random->next=head;
        ListNode* temp=random;
        while(temp->next!=NULL){
            if(temp->next->val==val){
                ListNode* node=temp->next;
                temp->next=node->next;
                delete node;
            }
            else temp=temp->next;
        }
        return random->next;
    }
};