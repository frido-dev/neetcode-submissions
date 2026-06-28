class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* left;
    Node* right;

    LRUCache(int capacity) {
        cap = capacity;

        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }
    
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    void insert(Node* node) {
        Node* nextNode = left->next;

        left->next = node;
        node->prev = left;
        node->next = nextNode;
        nextNode->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insert(node);
        } else {
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            insert(newNode);

            if (mp.size() > cap) {
                Node* lru = right->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            } 
        }
    }
};
