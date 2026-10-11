class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word){
            int i = c - 'a';
            if (!curr->children[i]) curr->children[i] = new TrieNode();
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }
    
    bool searchHelper(TrieNode* node, string word, int pos){
        if (pos == word.size()) return node->isEnd;

        char c = word[pos];
        if (c == '.'){
            for (int i = 0; i < 26; i++) if (node->children[i] && searchHelper(node->children[i], word, pos + 1)) return true;
            return false;
        }

        int i = c - 'a';
        if (!node->children[i]) return false;
        return searchHelper(node->children[i], word, pos + 1);
    }

    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};
