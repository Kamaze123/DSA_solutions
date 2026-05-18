class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 || j == 0 || i == row-1 || j == col - 1){
                    if(board[i][j] == 'O'){
                        dfs(board, i, j);
                    }
                }
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O'){board[i][j] = 'X';}
                else if(board[i][j] == '#'){board[i][j] = 'O';}
            }
        }
    }

    void dfs(vector<vector<char>>& board, int row, int col){
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()){
            return;
        }

        if(board[row][col] != 'O'){return;}

        board[row][col] = '#';

        dfs(board, row+ 1, col);
        dfs(board, row-1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }
};