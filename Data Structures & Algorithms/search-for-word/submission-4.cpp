class Solution {
public:
    int find = 0;
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> directions = {{1,0},{-1,0}, {0,1}, {0,-1}};
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> seen(row,  vector<int>(col, 0));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                string curr = "";
                curr += board[i][j];
                seen[i][j] = 1;
                dfs(seen, board, directions, i, j, row, col, word, curr);
                seen[i][j] = 0;
                if(find == 1){return true;}
            }
        }
        return false;
    }

    void dfs(vector<vector<int>>& seen,vector<vector<char>>& board, vector<vector<int>>& directions, int i, int j,  int row, int col, string word, string curr){
        if(curr.size() == word.size()){
            if(curr == word){find = 1;}
            return;
        }

        for(auto dir : directions){
            int x = dir[0];
            int y = dir[1];
            if(i + x  < 0 || j+ y < 0 || i+x >= row || j + y >= col ){continue;}
            if(seen[i+x][j+y] == 1){continue;}
        
            curr += board[i+x][j+y];
            seen[i+x][j+y] = 1;
            dfs(seen,board, directions, i+x, j+y, row, col, word, curr);
            curr.pop_back(); 
            seen[i+x][j+y] = 0;
        }
    }
};
