class DLN { // Double Linked Node
public:
    DLN* pre;
    DLN* next;
    int key;
    int val;
    DLN(int k, int v) {
        this->key = k;
        this->val = v;
    }
};

class LRUCache{
public:
    int c;
    int count;
    DLN* dummy1;
    DLN* dummy2;
    unordered_map<int, DLN*> m;

    LRUCache(int capacity) {
        this->c = capacity;
        this->count = 0;
        dummy1 = new DLN(0,0);
        dummy2 = new DLN(0,0);
        dummy1->next = dummy2;
        dummy2->pre = dummy1;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) {
            return -1;
        } else {
            DLN* hit = m[key];
            hit->pre->next = hit->next;
            hit->next->pre = hit->pre;
            
            hit->next = dummy1->next;
            dummy1->next = hit;
            hit->next->pre = hit;
            hit->pre = dummy1;
            return hit->val;
        }
    }
    
    void set(int key, int value) {
        if(m.find(key)==m.end()) {
            if(this->count < this->c) {
                DLN* n = new DLN(key, value);
                n->next = dummy1->next;
                dummy1->next = n;
                n->next->pre = n;
                n->pre = dummy1;
                m[key] = n;
                this->count++;
            } else {
                DLN* last = dummy2->pre;
                dummy2->pre = last->pre;
                last->pre->next = dummy2;
                
                m.erase(last->key);
                last->key = key;
                last->val = value;
                
                last->next = dummy1->next;
                dummy1->next = last;
                last->next->pre = last;
                last->pre = dummy1;
                m[key] = last;
            }
        } else {
            DLN* hit = m[key];
            hit->val = value;
            hit->pre->next = hit->next;
            hit->next->pre = hit->pre;
            
            hit->next = dummy1->next;
            dummy1->next = hit;
            hit->next->pre = hit;
            hit->pre = dummy1;
        }
    }
};
