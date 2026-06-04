class LFUCache {
private:
    struct Node {
        int key;
        int value;
        int freq;
        Node* prev;
        Node* next;  
        Node() : key(-1), value(-1), freq(0), prev(nullptr), next(nullptr) {}
        Node(int k, int v, int f) : key(k), value(v), freq(f), prev(nullptr), next(nullptr) {}
    };
    struct FreqList {
        Node* head;
        Node* tail;
        FreqList() {
            head = new Node();
            tail = new Node();
            head->next = tail;
            tail->prev = head;
        }
        bool isEmpty() {
            return head->next == tail;
        }
        void pushFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        Node* popBack() {
            if (isEmpty())
             return nullptr;
            Node* lastNode = tail->prev;
            remove(lastNode);
             return lastNode;
        }
    };
    int cap;
    int size;
    int min_freq;
    Node* key_to_node[100001];
    FreqList* freq_to_list[200005];
    void updateFrequency(Node* node) {
        int old_freq = node->freq;
        int new_freq = old_freq + 1;
        node->freq = new_freq;
        freq_to_list[old_freq]->remove(node);
        if (freq_to_list[min_freq]->isEmpty() && min_freq == old_freq) {
            min_freq++;
        }
        if (freq_to_list[new_freq] == nullptr) {
            freq_to_list[new_freq] = new FreqList();
        }
        freq_to_list[new_freq]->pushFront(node);
    }
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        min_freq = 0;
        for (int i = 0; i <= 100000; i++) {
            key_to_node[i] = nullptr;
        }
        for (int i = 0; i <= 200004; i++) {
            freq_to_list[i] = nullptr;
        }
    }
    int get(int key) {
        if (cap == 0 || key < 0 || key > 100000 || key_to_node[key] == nullptr) {
            return -1;
        }

        Node* node = key_to_node[key];
        updateFrequency(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cap == 0 || key < 0 || key > 100000) 
            return;
        if (key_to_node[key] != nullptr) {
            Node* node = key_to_node[key];
            node->value = value;
            updateFrequency(node);
                return;
        }
        if (size >= cap) {
            FreqList* min_list = freq_to_list[min_freq];
            Node* evictedNode = min_list->popBack();
            if (evictedNode != nullptr) {
                key_to_node[evictedNode->key] = nullptr;
                delete evictedNode;
                size--;
            }
        }
        Node* newNode = new Node(key, value, 1);
        key_to_node[key] = newNode;
        min_freq = 1;
        if (freq_to_list[1] == nullptr) {
            freq_to_list[1] = new FreqList();
        }
        freq_to_list[1]->pushFront(newNode);
        size++;
    }
    ~LFUCache() {
        for (int i = 0; i <= 100000; i++) {
            if (key_to_node[i] != nullptr) {
                delete key_to_node[i];
            }
        }
        for (int i = 0; i <= 200004; i++) {
            if (freq_to_list[i] != nullptr) {
                delete freq_to_list[i];
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */