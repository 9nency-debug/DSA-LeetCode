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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int t = 0, r = n-1, b = m-1, l = 0;
        while(head != nullptr && t <= m/2 && r >= n/2){
            for(int i = t; i<=r; i++){
                if(head != nullptr){
                    ans[t][i] = head->val;
                    head = head->next;
                }
            }
            for(int i = t+1; i<=b-1; i++){
                if(head != nullptr){
                    ans[i][r] = head->val;
                    head = head->next;
                }
            }
            for(int i = r; i>=t; i--){
                if(head != nullptr){
                    ans[b][i] = head->val;
                    head = head->next;
                }
            }
            for(int i = b-1; i>=t+1; i--){
                if(head != nullptr){
                    ans[i][l] = head->val;
                    head = head->next;
                }
            }
            t++, r--, b--, l++;
        }
        return ans;
    }
};