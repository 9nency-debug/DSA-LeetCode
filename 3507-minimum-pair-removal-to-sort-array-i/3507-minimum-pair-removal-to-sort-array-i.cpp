class Node {
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class Solution {
public:
    bool isSorted(Node *head) {
        while(head && head->next) {
            if(head->data > head->next->data)
                return false;
            head = head->next;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums)
    {
        if(nums.size() <= 1)
            return 0;
        Node *head = new Node(nums[0]);
        Node *tail = head;
        for(int i = 1; i < nums.size(); i++)
        {
            Node *temp = new Node(nums[i]);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        int operations = 0;
        while(!isSorted(head))
        {
            Node *curr = head;
            Node *best = head;
            int minSum = INT_MAX;
            while(curr->next) {
                int s = curr->data + curr->next->data;
                if(s < minSum) {
                    minSum = s;
                    best = curr;
                }
                curr = curr->next;
            }
            Node *first = best;
            Node *second = best->next;
            Node *merged = new Node(first->data + second->data);
            merged->prev = first->prev;
            merged->next = second->next;
            if(first->prev)
                first->prev->next = merged;
            else
                head = merged;
            if(second->next)
                second->next->prev = merged;
            delete first;
            delete second;
            operations++;
        }
        return operations;
    }
};
