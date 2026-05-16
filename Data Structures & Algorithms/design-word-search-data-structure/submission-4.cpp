class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        for(int i = 0;i < 26; i++){
            children[i] = nullptr;
        }

        isEnd = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';

            if(node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return dfs(word, 0, node);
    }

    bool dfs(string word, int index, TrieNode* curr){
        TrieNode* root = curr;
        for(int i = index; i < word.length(); i++){
            if(word[i] == '.'){

                for(TrieNode* child : root->children){
                    if(child != nullptr && dfs(word, i+1, child)){return true;}
                }

                return false;
            }else{
                char ch = word[i];
                int id = ch - 'a';

                if(root->children[id] == nullptr){return false;}
                root = root->children[id];
            }
        }
        return root->isEnd;
    }
};
