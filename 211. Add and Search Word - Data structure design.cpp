#include <iostream>
#include <vector>
using namespace std;

class WordDictionary {
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
    WordDictionary() {
        root = new TrieNode;
    }
    
    ~WordDictionary() {
        delete root;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch: word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchNode(word.c_str(), root);
    }

private:
    bool searchNode(const char* s, TrieNode* node) {
        for (int i=0; s[i] != '\0'; ++i) {
            if (s[i] != '.') {
                if (node->containsKey(s[i])) {
                    node = node->get(s[i]);
                } else {
                    return false;
                }
            } else {
                TrieNode* tmp = node;
                for (char ch='a'; ch <= 'z'; ++ch) {
                    if (!(tmp->containsKey(ch))) continue;
                    node = tmp->get(ch);
                    if (searchNode(s+i+1, node)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return node->isEnd();
    }
};

int main() {
    cout << boolalpha;
    WordDictionary trie;
    trie.addWord("abcd");
    cout << trie.search("abc") << endl;
    cout << trie.search("abc.") << endl;
    cout << trie.search("....") << endl;
    return 0;
}
