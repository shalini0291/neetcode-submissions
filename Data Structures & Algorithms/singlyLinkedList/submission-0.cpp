class ListNode {
    public:
    int val;
    ListNode* next;

    //constructor that sets 'next' to nullptr by default
    ListNode(int val) : val(val), next(nullptr) {}

    //constructor that accepts both values and. next node
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};
class LinkedList {
private:
    ListNode* head;
    ListNode* tail;
public:
    //constructor
    LinkedList() {
        //init the list with a 'dummy' node which makes
        // removing a node from the beginning of list easier.
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* curr = head->next;
        int i=0;
        while(curr!=nullptr)
        {
            if(i==index)
            {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1;
    }

    //method to insert at the head
    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
        if(newNode->next == nullptr){
            tail = newNode;
        }
    }
    
    //method to insert at the tail
    void insertTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    //method to remove at the given index
    bool remove(int index) {
        int i=0;
        ListNode* curr = head;
        while(i<index && curr!=nullptr)
        {
            i++;
            curr = curr->next;
        }

        //remove the node ahead of curr
        if(curr!=nullptr && curr->next != nullptr){
            if(curr->next == tail) {
                tail = curr;
            }
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    // method to get values of the linked list
    vector<int> getValues() {
        vector<int> res;
        ListNode* curr = head->next;
        while(curr!=nullptr)
        {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};
