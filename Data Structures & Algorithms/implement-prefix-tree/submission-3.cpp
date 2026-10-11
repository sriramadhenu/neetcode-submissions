class PrefixTree {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    TrieNode* root;
    
public:
    PrefixTree() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word){
            int i = c - 'a';
            if (!curr->children[i]) curr->children[i] = new TrieNode;
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word){
            int i = c - 'a';
            if (!curr->children[i]) return false;
            else curr = curr->children[i];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix){
            int i = c - 'a';
            if (!curr->children[i]) return false;
            curr = curr->children[i];
        }
        return true;
    }
};
