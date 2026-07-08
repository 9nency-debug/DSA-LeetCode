class Node {
public:
    char ch;
    Node* prev;
    Node* next;
    Node(char ch = '\0', Node* prev = nullptr, Node* next = nullptr) : 
        ch(ch), prev(prev), next(next) {}
};
class TextEditor {
    private:
    Node* head;
    Node* tail;
    Node* cursor;
    std::string _get_left_text() {
        std::string text;
        Node* curr = cursor;
        int count = 0;
        while (curr != head && count < 10) {
            text += curr->ch; 
            curr = curr->prev;
            count++;
        }
        std::reverse(text.begin(), text.end());
        return text;
    }
public:
    TextEditor() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        cursor = head;  
    }
    
    void addText(string text) {
        for (char ch : text) {
            Node* new_node = new Node(ch);
            new_node->prev = cursor;
            new_node->next = cursor->next;
            cursor->next->prev = new_node;
            cursor->next = new_node;
            cursor = new_node;
        }
    }
    
    int deleteText(int k) {
        int count = 0;
        while (k > 0 && cursor != head) {
            Node* prev_node = cursor->prev;
            prev_node->next = cursor->next;
            cursor->next->prev = prev_node;
            cursor = prev_node;
            k--;
            count++;
        }
        return count;
    }
    
    string cursorLeft(int k) {
        while (k > 0 && cursor != head) {
            cursor = cursor->prev;
            k--;
        }
        return _get_left_text();
    }
    string cursorRight(int k) {
        while (k > 0 && cursor->next != tail) {
            cursor = cursor->next;
            k--;
        }
        return _get_left_text();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */