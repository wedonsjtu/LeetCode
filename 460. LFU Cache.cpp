#include <iostream>
#include <unordered_map>
using namespace std;

// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

// Note that the number of times an item is used is the number of calls to the get and put functions for that item since it was inserted. This number is set to zero when the item is removed.

class LFUCache {
private:
    struct node {
        int key;
        int val;
        node *prev, *next;
        node *plus, *minus;
        node(int k, int v): key(k), val(v), prev(NULL), next(NULL), plus(NULL), minus(NULL) {}
    };

    node *head, *tail;
    int remain;
    std::unordered_map<int, node*> m;

public:
    LFUCache(int capacity):m() {
        remain = capacity;
        head = new node(0,0);
        tail = new node(0,0);
        head->plus = tail;
        tail->minus = head;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        int ans = 0;
        node* now_node = m[key];
        ans = now_node->val;
        node* pre = now_node->prev;
        node* nex = now_node->next;
        pre->next = nex;
        if (nex) nex->prev = pre;
        while (pre->prev) {
            pre = pre->prev;
        }  // now pre is head
        node* now_head = pre;
        if (pre->key + 1 != pre->plus->key) {
            node* tmp = new node(pre->key+1, 0);
            tmp->plus = pre->plus;
            pre->plus->minus = tmp;
            pre->plus = tmp;
            tmp->minus = pre;
        }

        pre = pre->plus;
        node* ttmp = pre->next;
        pre->next = now_node;
        now_node->prev = pre;
        now_node->next = ttmp;
        if (ttmp) ttmp->prev = now_node;
        
        if (!now_head->next) {
            node* pre = now_head->minus;
            node* nex = now_head->plus;
            pre->plus = nex;
            nex->minus = pre;
            delete now_head;
        }
        // print();
        return ans;
    }
    
    void put(int key, int value) {
        if (head->plus == tail && remain == 0) return;
        if (m.find(key) != m.end()) {
            node* now_node = m[key];
            now_node->val = value;
            get(key);
            return;
            // node* now_node = m[key];
            // node* pre = now_node->prev;
            // node* nex = now_node->next;
            // pre->next = nex;
            // if (nex) nex->prev = pre;
            // node* now_head = now_node;
            // while (now_head->prev) {
            //     now_head = now_head->prev;
            // }
            // if (!now_head->next) {
            //     node* pre = now_head->minus;
            //     node* nex = now_head->plus;
            //     pre->plus = nex;
            //     nex->minus = pre;
            //     delete now_head;
            // }
            // delete now_node;
            // remain++;
        }

        if (remain == 0) {
            node* tmp = head->plus;
            while (tmp->next) {
                tmp = tmp->next;
            }
            node* pre = tmp->prev;
            pre->next = NULL;
            m.erase(tmp->key);
            node* now_head = tmp;
            while (now_head->prev) {
                now_head = now_head->prev;
            }
            if (!now_head->next) {
                node* pre = now_head->minus;
                node* nex = now_head->plus;
                pre->plus = nex;
                nex->minus = pre;
                delete now_head;
            }
            delete tmp;
        }
        else remain--;

        node* now_node = new node(key, value);
        m[key] = now_node;

        if (head->plus->key != 1) {
            node* tmp = new node(1, 0);
            tmp->plus = head->plus;
            head->plus->minus = tmp;
            head->plus = tmp;
            tmp->minus = head;
        }

        node* pre = head->plus;
        node* ttmp = pre->next;
        pre->next = now_node;
        now_node->prev = pre;
        now_node->next = ttmp;
        if (ttmp) ttmp->prev = now_node;
    }

    void print() {
        // for (auto it=m.begin(); it!=m.end();++it) {
        //     cout << it->first << ' ' << it->second->key << ' ' << it->second->val << endl;
        // }
        cout << endl;
        cout << "----------------" << endl;
        node* tmp = head->plus;
        while (tmp != tail) {
            cout << tmp->key << ':';
            node* t = tmp->next;
            while (t) {
                cout << t->key << ',' << t->val << ' '; 
                t = t->next;
            }
            cout << endl;
            tmp = tmp->plus;
        }
        cout << "----------------" << endl;
        cout << endl;
    }

    ~LFUCache() {
        node* tmp = head;
        node* tt, *ttt, *t4;
        while (tmp) {
            tt = tmp->next;
            while (tt) {
                ttt = tt;
                tt = tt->next;
                delete ttt;
            }
            t4 = tmp;
            tmp = tmp->plus;
            delete t4;
        }
    }
};

int main() {
    LFUCache cache(10);
    cache.print();
    cache.put(10, 13);
    cache.print();
    cache.put(3, 17);
    cache.print();
    cache.put(6, 11);
    cache.print();
    cache.put(10, 5);
    cache.print();
    cache.put(9, 10);
    cache.print();
    cache.get(13);
    cache.print();
    cache.put(2, 19);
    cache.print();
    cache.get(2);
    cache.print();
    cache.get(3);
    cache.print();
    cache.put(5, 25);
    cache.print();
    cache.get(8);
    cache.print();
    cache.put(9, 22);
    cache.print();
    cache.put(5, 5);
    cache.print();
    cache.put(1, 30);
    cache.print();
    cache.get(11);
    cache.print();
    cache.put(9, 12);
    cache.print();
    cache.get(7);
    cache.print();
    cache.get(5);
    cache.print();
    cache.get(8);
    cache.print();
    cache.get(9);
    cache.print();
    cache.put(4, 30);
    cache.print();
    cache.put(9, 3);
    cache.print();
    cache.get(9);
    cache.print();
    cache.get(10);
    cache.print();
    cache.get(10);
    cache.print();
    cache.put(6, 14);
    cache.print();
    cache.put(3, 1);
    cache.print();
    cache.get(3);
    cache.print();
    cache.put(10, 11);
    cache.print();
    cache.get(8);
    cache.print();
    cache.put(2, 14);
    cache.print();
    cache.get(1);
    cache.print();
    cache.get(5);
    cache.print();
    cache.get(4);
    cache.print();
    cache.put(11, 4);
    cache.print();
    cache.put(12, 24);
    cache.print();
    cache.put(5, 18);
    cache.print();
    cache.get(13);
    cache.print();
    cache.put(7, 23);
    cache.print();
    cache.get(8);
    cache.print();
    cache.get(12);
    cache.print();
    cache.put(3, 27);
    cache.print();
    cache.put(2, 12);
    cache.print();
    cache.get(5);
    cache.print();
    cache.put(2, 9);
    cache.print();
    cache.put(13, 4);
    cache.print();
    cache.put(8, 18);
    cache.print();
    cache.put(1, 7);
    cache.print();
    cache.get(6);
    cache.print();
    cache.put(9, 29);
    cache.print();
    cache.put(8, 21);
    cache.print();
    cache.get(5);
    cache.print();
    cache.put(6, 30);
    cache.print();
    cache.put(1, 12);
    cache.print();
    cache.get(10);
    cache.print();
    cache.put(4, 15);
    cache.print();
    cache.put(7, 22);
    cache.print();
    cache.put(11, 26);
    cache.print();
    cache.put(8, 17);
    cache.print();
    cache.put(9, 29);
    cache.print();
    cache.get(5);
    cache.print();
    cache.put(3, 4);
    cache.print();
    cache.put(11, 30);
    cache.print();
    cache.get(12);
    cache.print();
    cache.put(4, 29);
    cache.print();
    cache.get(3);
    cache.print();
    cache.get(9);
    cache.print();
    cache.get(6);
    cache.print();
    cache.put(3, 4);
    cache.print();
    cache.get(1);
    cache.print();
    cache.get(10);
    cache.print();
    cache.put(3, 29);
    cache.print();
    cache.put(10, 28);
    cache.print();
    cache.put(1, 20);
    cache.print();
    cache.put(11, 13);
    cache.print();
    cache.get(3);
    cache.print();
    cache.put(3, 12);
    cache.print();
    cache.put(3, 8);
    cache.print();
    cache.put(10, 9);
    cache.print();
    cache.put(3, 26);
    cache.print();
    cache.get(8);
    cache.print();
    cache.get(7);
    cache.print();
    cache.get(5);
    cache.print();
    cache.put(13, 17);
    cache.print();
    cache.put(2, 27);
    cache.print();
    cache.put(11, 15);
    cache.print();
    cache.get(12);
    cache.print();
    cache.put(9, 19);
    cache.print();
    cache.put(2, 15);
    cache.print();
    cache.put(3, 16);
    cache.print();
    cache.get(1);
    cache.print();
    cache.put(12, 17);
    cache.print();
    cache.put(9, 1);
    cache.print();
    cache.put(6, 19);
    cache.print();
    cache.get(4);
    cache.print();
    cache.get(5);
    cache.print();
    cache.get(5);
    cache.print();
    cache.put(8, 1);
    cache.print();
    cache.put(11, 7);
    cache.print();
    cache.put(5, 2);
    cache.print();
    cache.put(9, 28);
    cache.print();
    cache.get(1);
    cache.print();
    cache.put(2, 2);
    cache.print();
    cache.put(7, 4);
    cache.print();
    cache.put(4, 22);
    cache.print();
    cache.put(7, 24);
    cache.print();
    cache.put(9, 26);
    cache.print();
    cache.put(13, 28);
    cache.print();
    cache.put(11, 26);
    cache.print();
    return 0;
}
