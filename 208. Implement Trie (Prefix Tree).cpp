#include <iostream>
using namespace std;

class Trie {
private:
    class TrieNode {
    private:
        const int length = 26;
        TrieNode** links;
        bool end;
    public:
        TrieNode() {
            links = new TrieNode*[length]();
            end = false;
        }
        
        ~TrieNode() {
            for (int i=0; i < length; ++i) {
                if (links[i] != NULL) {
                    delete links[i];
                    links[i] = NULL;
                }
            }
            delete[] links;
        }
        
        bool containsKey(char ch) {
            return links[ch-'a'];
        }
        TrieNode* get(char ch) {
            return links[ch-'a'];
        }
        void put(char ch, TrieNode* node) {
            links[ch - 'a'] = node;
        }
        void setEnd() {
            end = true;
        }
        bool isEnd() {
            return end;
        }
    };
    
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char ch: word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (char ch: word) {
            if (node->containsKey(ch)) {
                node = node->get(ch);
            }
            else return false;
        }
        return node->isEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch: prefix) {
            if (node->containsKey(ch)) {
                node = node->get(ch);
            }
            else return false;
        }
        return true;
    }
};

int main() {
    cout << boolalpha;
    Trie trie;
    trie.insert("abcd");
    cout << trie.search("abc") << endl;
    cout << trie.startsWith("abc") << endl;
    return 0;
}
