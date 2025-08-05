class Trie {
    private:
        struct TrieNode {
            TrieNode* children[26];
            vector<string> suggestions;

            TrieNode() {
                for (int i = 0; i < 26; i++) {
                    children[i] = nullptr;
                }
            }
        };
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(const string& word) {
            TrieNode* node = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (node->children[idx] == nullptr) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
                if (node->suggestions.size() < 3) node->suggestions.push_back(word);
            }
        }

        vector<vector<string>> search(const string& word) {
            vector<vector<string>> res;
            TrieNode* node = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (node && node->children[idx] != nullptr) {
                    node = node->children[idx];
                    res.push_back(node->suggestions);
                } else {
                    res.push_back({});
                    node = nullptr;
                }
            }
            return res;
        }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie* trie = new Trie();
        for (string word : products) {
            trie->insert(word);
        }
        return trie->search(searchWord);
    }
};