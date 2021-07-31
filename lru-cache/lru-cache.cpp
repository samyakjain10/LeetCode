class LRUCache {
public:
    
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
        
            Node(int k, int v){
                key = k;
                val = v;
            }  
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int, Node*> m;
    
    LRUCache(int capacity) {
        
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    
    void addNode(Node* newNode){
        
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        
    }
    
    void deleteNode(Node* delNode){
        Node* delprev = delNode->prev;
        Node* delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int _key) {
        
        if(m.find(_key) != m.end()){
            Node* resNode = m[_key];
            int res = resNode->val;
            m.erase(_key);
            deleteNode(resNode);
            addNode(resNode);
            m[_key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int _key, int value) {
        if(m.find(_key) != m.end()){
            Node* existingNode = m[_key];
            m.erase(_key);
            deleteNode(existingNode);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(_key,value));
        m[_key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */