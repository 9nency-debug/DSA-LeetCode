struct Node {
    Node *prev;
    Node *next;
    Node *bottom;
    int value;
    
    Node (Node *prev, Node *next, Node *bottom, int value): prev(prev), next(next), bottom(bottom), value(value){}
};
class Skiplist {
public:
    unordered_map<int, pair<Node *, Node *>> level_to_list;
    int num_levels = 10;
    random_device rd;
    mt19937 gen;
    bernoulli_distribution coin;
    Skiplist() {
        Node *prev_head = nullptr;
        Node *prev_tail = nullptr;
        for (int level = 0; level < num_levels; ++level) {
            Node *head = new Node(nullptr, nullptr, prev_head, -1);
            Node *tail = new Node(nullptr, nullptr, prev_tail, -1);
            head->next = tail;
            tail->prev = head;
            level_to_list[level] = {head, tail};
            prev_head = head;
            prev_tail = tail;
        }
        gen = mt19937(rd());
        coin = bernoulli_distribution(0.5);
    }
    bool search_helper(Node *start, Node *end, int search_value, int level) {
        Node *less_than_node = start;
        Node *greater_than_node = end;
        Node *curr = start->next;
        while (curr != end) {
            if (curr->value == search_value) return true;
            else if (curr->value > search_value) {
                greater_than_node = curr;
                break;
            }
            less_than_node = curr;
            curr = curr->next;
        }
        if (level == 0) return false;
        return search_helper(less_than_node->bottom, greater_than_node->bottom, search_value, level - 1);
    }
    bool search(int target) {
        return search_helper(level_to_list[num_levels - 1].first, level_to_list[num_levels - 1].second, target, num_levels - 1);
   
    }
    Node * add_helper(Node *start, Node *end, int search_value, int level) {
        Node *less_than_node = start;
        Node *greater_than_node = end;
        Node *curr = start->next;
        while (curr != end) {
            if (curr->value >= search_value) {
                greater_than_node = curr;
                break;
            }
            less_than_node = curr;
            curr = curr->next;
        }
        Node *bottom = (level != 0) ? add_helper(less_than_node->bottom, greater_than_node->bottom, search_value, level - 1) : nullptr;
        if (level == 0 || bottom) {
            Node *new_node = new Node(less_than_node, greater_than_node, bottom, search_value);
            less_than_node->next = new_node;
            greater_than_node->prev = new_node;
            return coin(gen) ? new_node : nullptr;
        } else {
            return nullptr;
        }
    }
    void add(int num) {
        add_helper(level_to_list[num_levels - 1].first, level_to_list[num_levels - 1].second, num, num_levels - 1);   
    }
    void remove_chain(Node *node) {
        if (node == nullptr) return;
        remove_chain(node->bottom);
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    bool erase_helper(Node *start, Node *end, int search_value, int level) {
        Node *less_than_node = start;
        Node *greater_than_node = end;
        Node *curr = start->next;
        while (curr != end) {
            if (curr->value == search_value) {
                remove_chain(curr);
                return true;
            }
            else if (curr->value > search_value) {
                greater_than_node = curr;
                break;
            }
            less_than_node = curr;
            curr = curr->next;
        }
        if (level == 0) {
            return false;
        }
        return erase_helper(less_than_node->bottom, greater_than_node->bottom, search_value, level - 1);
    }
    bool erase(int num) {
        return erase_helper(level_to_list[num_levels - 1].first, level_to_list[num_levels - 1].second, num, num_levels - 1);
    }

};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
