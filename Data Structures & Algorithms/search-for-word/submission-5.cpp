class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();


        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(dfs(board, 0, i,j, word)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int x, int y, string word){
            if(i == word.size()){
                return true;
            }

            if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()){
                return false;
            }

            if(board[x][y] != word[i]){
                return false;
            }

            char temp = board[x][y];
            board[x][y]= '#';

            int found = dfs(board, i+1, x+1, y, word) ||
                                    dfs(board, i+1, x, y+1, word) ||
                                    dfs(board, i+1, x-1, y, word) ||
                                    dfs(board, i+1, x, y-1, word);
            
            board[x][y] = temp;
            return found;
    }        
};
