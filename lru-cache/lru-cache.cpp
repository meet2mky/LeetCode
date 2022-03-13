class Node{
public:
    Node* prev;
    Node* next;
    int value;
    int key;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};
class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        this->head = this->tail = NULL;
        this->size = 0;
    }
    void insertHead(Node* d){
        size++;
        if(head == NULL){ // First Insert
            head = tail = d;
            return;
        } 
        // Second or Third ... insert
        d->next = head;
        head->prev = d;
        head = d;
    }
    void remove(Node* a){
        size--;
        if(a == head && a == tail){// Case: a == head and a == tail
            head = tail = NULL;
        }
        else if(a == head){// Case: a == head
            head = head->next;
            head->prev = NULL;
        }else if(a == tail){ // Case: a == tail
            tail = tail->prev;
            tail->next = NULL;
        }else{
        // Case: Neither
        Node* aPrev = a->prev;
        Node* aNext = a->next;
        aPrev->next = aNext;
        aNext->prev = aPrev;
        }
    }
    int getSize(){
        return this->size;
    }
};

class LRUCache {
    unordered_map<int, Node*> ump;
    LinkedList list;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(ump.find(key) == ump.end()) return -1;
        Node* add = ump[key];
        list.remove(add);
        add->next = add->prev = NULL;
        list.insertHead(add);
        return add->value;
    }
    
    void put(int key, int value) {
        if(ump.find(key) == ump.end()){
            if(list.getSize() >= capacity){
                ump.erase(list.tail->key);
                list.remove(list.tail);
            }
            Node* toAdd = new Node(key, value);
            ump[key] = toAdd;
            list.insertHead(toAdd);
        }
        Node* add = ump[key];
        add->value = value;
        list.remove(add);
        add->next = add->prev = NULL;
        list.insertHead(add);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */