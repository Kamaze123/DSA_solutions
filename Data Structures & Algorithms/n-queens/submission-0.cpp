class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
          //initialization
        vector<string> seen(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                seen[i].push_back('x');
            }
        }
        vector<string> curr;
        string curr_row;
        for(int i = 0; i < n; i++){
            curr_row.push_back('.');
        }
        backtrack(seen, curr, curr_row, 0, n);
        return ans;
    }

    void backtrack(vector<string>& seen, vector<string>& curr, string curr_row, int row, int n){
        if(row == n){
            ans.push_back(curr);
            return;
        }

        for(int j = 0; j < n; j++){
            if(seen[row][j] == 'x'){
                vector<string> temp = seen;
                updateArray(seen, row, j, n);
                string temp_row = curr_row;
                curr_row[j] = 'Q';
                curr.push_back(curr_row);
                backtrack(seen, curr, temp_row, row+1, n);
                seen = temp;
                curr_row = temp_row;
                curr.pop_back();
            }
        }
    }

    void updateArray(vector<string>& seen, int row, int col, int n){
        for(int i = 0; i < n; i++){
            seen[row][i] = '.';
            seen[i][col] = '.';
        }
        
        updateDiagonal1(seen, row+1, col+1, n);
        updateDiagonal2(seen, row+1, col-1, n);
        updateDiagonal3(seen, row-1, col+1, n);
        updateDiagonal4(seen, row-1, col-1, n);

        seen[row][col] = '.';
    }

    void updateDiagonal1(vector<string>& seen, int row, int col, int n){
        if(row >= n || col >= n || row < 0 || col < 0){
            return;
        }

        seen[row][col] = '.';
        updateDiagonal1(seen, row+1, col + 1, n);
    }

    void updateDiagonal2(vector<string>& seen, int row, int col, int n){
        if(row >= n || col >= n || row < 0 || col < 0){
            return;
        }

        seen[row][col] = '.';
        updateDiagonal2(seen, row+1, col -1, n);
    }

    void updateDiagonal3(vector<string>& seen, int row, int col, int n){
        if(row >= n || col >= n || row < 0 || col < 0){
            return;
        }

        seen[row][col] = '.';
        updateDiagonal3(seen, row-1, col + 1, n);
    }

    void updateDiagonal4(vector<string>& seen, int row, int col, int n){
        if(row >= n || col >= n || row < 0 || col < 0){
            return;
        }

        seen[row][col] = '.';
        updateDiagonal4(seen, row-1, col-1, n);
    }
};
