class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        vector<vector<char>> temp = grid;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(temp[i][j] == '1'){
                    ans++;
                    dfs(temp, i, j);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != '1'){
            return;
        }

        grid[row][col] = '#';

        dfs(grid, row+1, col);
        dfs(grid, row, col+1);
        dfs(grid, row-1, col);
        dfs(grid, row, col-1);
    }
};
