class TrieNode{
    public:
        TrieNode* children[26]; 
        bool isEnd;

        TrieNode(){
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
            isEnd = false;
        } 
};

class Solution {
   public:
    TrieNode* root = new TrieNode();
    vector<string> ans;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word : words){
            insert(word);
        }

        int row = board.size();
        int col = board[0].size();

        TrieNode* curr = root;

        for(int i = 0; i < board.size();i++){
            for(int j = 0; j < board[0].size(); j++){
                int idx = board[i][j] - 'a';
                if(curr->children[idx] != nullptr){
                    dfs(board, i, j , "", curr);
                }
            }
        }
        return ans;        
    }

    void dfs(vector<vector<char>>& board, int row , int col, string word, TrieNode* curr){
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()){
            return;
        }

        char ch = board[row][col];

        if(ch == '#'){return;}

        int idx = ch - 'a';

        if(curr->children[idx] == nullptr){return;}

        curr = curr->children[idx];
        word.push_back(ch);

        if(curr->isEnd == true){
            ans.push_back(word);
            curr->isEnd = false;
        }

        board[row][col] = '#';


        dfs(board, row+1, col,  word, curr);
        dfs(board, row, col + 1,  word, curr);
        dfs(board, row-1, col,  word, curr);
        dfs(board, row, col-1,  word, curr);

        board[row][col] = ch;
        word.pop_back();
    }

    void insert(string word){
        TrieNode* curr =  root;
        for(char ch : word){
            int index = ch - 'a';

            if(curr->children[index] == nullptr){
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

};
