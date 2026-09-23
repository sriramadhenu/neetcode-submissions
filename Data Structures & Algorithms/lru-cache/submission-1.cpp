class LRUCache {
private:
    struct Node{
        int key, val;
        Node* next, *prev;
    };
    unordered_map<int, Node*> mapping;
    Node* head, *tail;
    int maxcapacity;

    void remove(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void insertAtFront(Node* n){
        n->next = head->next;
        head->next = n;
        n->prev = head;
        n->next->prev = n;
    }
public:
    LRUCache(int capacity) {
        maxcapacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!mapping.count(key)) return -1;
        else {
            remove(mapping[key]);
            insertAtFront(mapping[key]);
            return mapping[key]->val;
        }
    }
    
    void put(int key, int value) {
        if (!mapping.count(key)) {
            // doesn't exist: add it to the cache
            // check if the cache is full
            if (mapping.size() == maxcapacity){
                // must evict least recently used (tail)
                Node* lru = tail->prev;
                remove(tail->prev);
                mapping.erase(lru->key);
                delete lru;
            }
            // finally, add the new {key, value} node into mapping, and insert it at the front of the
            // doubly linked list
            Node* n = new Node{key, value, nullptr, nullptr};
            insertAtFront(n);
            mapping[key] = n;
        } else {
            // it does exist, update the value
            Node* n = mapping[key]; // this is the node to be updated
            n->val = value;
            remove(n);
            insertAtFront(n);
        }
    }
};
