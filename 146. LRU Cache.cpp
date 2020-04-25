#include <iostream>
#include <unordered_map>
using namespace std;

// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

class LRUCache {
private:
    struct node {
        int key;
        int val;
        node *prev, *next;
        node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}
    };

    node *head, *tail;
    int remain;
    std::unordered_map<int, node*> m;

public:
    LRUCache(int capacity): m() {
        remain = capacity;
        head = new node(0,0);
        tail = new node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        node* now_node = m[key];
        node* pre = now_node->prev;
        node* nex = now_node->next;
        pre->next = nex;
        nex->prev = pre;
        node* head_nex = head->next;
        head->next = now_node;
        now_node->prev = head;
        now_node->next = head_nex;
        head_nex->prev = now_node;
        return now_node->val;
    }
    
    void put(int key, int value) {
        if (head->next == tail && remain == 0) return;
        if (m.find(key) != m.end()) {
            m[key]->val = value;
            get(key);
            return;
        }
        node* now_node = new node(key, value);
        node* head_nex = head->next;
        head->next = now_node;
        now_node->prev = head;
        now_node->next = head_nex;
        head_nex->prev = now_node;
        m.insert({key, now_node});
        if (remain == 0) {
            node* now_node = tail->prev;
            node* pre = now_node->prev;
            node* nex = now_node->next;
            pre->next = nex;
            nex->prev = pre;
            m.erase(now_node->key);
            delete now_node;
        }
        else --remain;
    }

    ~LRUCache() {
        node* tmp;
        while (head) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4
    return 0;
}
