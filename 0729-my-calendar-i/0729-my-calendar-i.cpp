
class node{
    public:
    int start;
    int end;
    node*left;
    node*right;
    node(int start,int end){
        this->start=start;
        this->end=end;
        left=NULL;
        right=NULL;
    }
};

class MyCalendar {
public:
    node*root;
    MyCalendar() {
        root=NULL;
    }
    
    bool book(int start, int end) {
        if(root==NULL){
            root=new node(start,end);
            return true;
        }
        return insert_in_bst(root,start,end)==NULL?false:true;
    }
    node*insert_in_bst(node*curr,int start,int end){
        if(start>=curr->end){
            if(curr->right==NULL){
                curr->right= new node(start,end);
                return curr->right;
            }
            return insert_in_bst(curr->right,start,end);
        }
        else if(end<=curr->start){
            if(curr->left==NULL){
                curr->left=new node(start,end);
                return curr->left;
            }
            return insert_in_bst(curr->left,start,end);
        } else {
            return NULL;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end)
 ;
 */

