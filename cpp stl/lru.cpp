class LRUCache {
public:

class node{
    int key;
    int val;
    int node* next;
    int node* prev;
    node(int key_,int _val){
    key = key_;
    val = _val;
    }
};

node* head = new node(-1,-1);
node* tail = new node(-1,-1);

int cap;
unordered_map<int,node*> m;

    void addNode(node* newNode){
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    }

    void delNode(node* delNode);
    node* delnext = delnode->next;
    node* delprev = delnode->next;
    delprev->next = delnext;
    delnext->prev = delprev;

    
    LRUCache(int capacity) {
        cap = capacity;
        head-> next = tail;
        tail->prev = head;
        
    }

    int get(int key) {
        if(m.find(key_)!=m.end()){
        node* resNode = m[key_];
        int res = resNode ->val;
        addNode(resNode)
        m[key_]=head->next;
        return res; 
        }
        return -1;      
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */