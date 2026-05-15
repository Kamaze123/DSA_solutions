class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                 board[i].push_back('.');
            }
        }
        backtrack(board, 0, n);
        return ans;
    }

    void backtrack(vector<string>& board, int row, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(cols.count(col) || posDiag.count(row + col) || negDiag.count(row - col)){
                continue;
            }

            board[row][col] = 'Q';
            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);

            backtrack(board, row + 1, n);

            negDiag.erase(row - col);
            posDiag.erase(row + col);
            cols.erase(col);
            board[row][col] = '.';
        }
    }
};
