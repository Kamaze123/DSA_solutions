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

    bool dfs(string word, int index, TrieNode* root){
        if(word.length() == index){
            return root->isEnd;
        }
        char ch = word[index];
        if(ch == '.'){
            for(int i = 0; i < 26; i++){
                if(root->children[i] != nullptr){
                    if(dfs(word, index+ 1, root->children[i])){
                        return true;
                    }
                }
            }
            return false;
        }else{

        int id = ch - 'a';
        if(root->children[id] == nullptr){return false;}
        
        return dfs(word, index + 1, root->children[id]);
        }
    }
};
