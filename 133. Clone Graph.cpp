#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        // 遍历一遍所有节点，保存原始节点指针
        unordered_map<int, Node*> origin_m, new_m;
        stack<int> s;
        origin_m[node->val] = node;
        new_m[node->val] = new Node(node->val, vector<Node*>());
        s.push(node->val);
        int tmp_id;
        while (!s.empty()) {
            tmp_id = s.top();
            s.pop();
            for (Node* neigh: origin_m[tmp_id]->neighbors) {
                if (origin_m.find(neigh->val) == origin_m.end()) {
                    origin_m[neigh->val] = neigh;
                    new_m[neigh->val] = new Node(neigh->val, vector<Node*>());
                    s.push(neigh->val);
                }
                new_m[tmp_id]->neighbors.push_back(new_m[neigh->val]);
            }
        }
        return new_m[1];
    }
};

void printGraph(Node* node) {
    if (!node) return;
    map<int, Node*> m;
    stack<int> s;
    m[node->val] = node;
    s.push(node->val);
    int tmp_id;
    while (!s.empty()) {
        tmp_id = s.top();
        s.pop();
        for (Node* neigh: m[tmp_id]->neighbors) {
            if (m.find(neigh->val) == m.end()) {
                m[neigh->val] = neigh;
                s.push(neigh->val);
            }
        }
    }
    for (auto p: m) {
        cout << p.first << ':' << ' ';
        for (auto neigh: p.second->neighbors) {
            cout << neigh->val << ' ';
        }
        cout << endl;
    }
}

int main() {
    Node* n1 = new Node(1, vector<Node*>());
    Node* n2 = new Node(2, vector<Node*>());
    Node* n3 = new Node(3, vector<Node*>());
    Node* n4 = new Node(4, vector<Node*>());
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);
    printGraph(n1);
    cout << "----------------" << endl;
    auto ans = Solution().cloneGraph(n1);
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    printGraph(ans);
    return 0;
}
