#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    class Trie { 
    private:
        // 208. Implement Trie (Prefix Tree) 
        // https://leetcode.com/problems/implement-trie-prefix-tree/
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
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> ans;
        if (words.empty() || board.empty() || board[0].empty()) {
            vector<string> res;
            return res;
        }
        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
        Trie trie;
        for (auto w: words) {
            trie.insert(w);
        }
        string prefix;
        for (int i=0; i < board.size(); ++i) {
            for (int j=0; j < board[0].size(); ++j) {
                backtracking(board, isVisited, trie, i, j, ans, prefix);
            }
        }
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
    
private:
    void backtracking(vector<vector<char>>& board, vector<vector<bool>>& isVisited, Trie& trie, int r, int c, set<string>& ans, string prefix) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return;
        if (isVisited[r][c]) return;
        isVisited[r][c] = true;
        prefix.push_back(board[r][c]);
        if (trie.startsWith(prefix)) {
            if (trie.search(prefix)) {
                ans.insert(prefix);
            }
            backtracking(board, isVisited, trie, r-1, c, ans, prefix);
            backtracking(board, isVisited, trie, r+1, c, ans, prefix);
            backtracking(board, isVisited, trie, r, c-1, ans, prefix);
            backtracking(board, isVisited, trie, r, c+1, ans, prefix);
        }
        isVisited[r][c] = false;
    }
};

int main() {
    vector<vector<char>> board{
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words{"oath","pea","eat","rain"};
    auto ans = Solution().findWords(board, words);
    for (auto i: ans) cout << i << ' ';
    cout << endl;
    return 0;
}
