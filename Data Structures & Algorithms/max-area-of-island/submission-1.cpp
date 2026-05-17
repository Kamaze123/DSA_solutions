class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;

        int row = grid.size();
        int col = grid[0].size();
        int val;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    val = dfs(grid, i, j);
                    maxi = max(maxi, val);
                }
            }
        }

        return maxi;
    }

    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 1){
            return 0;
        }

        int area = 1;
        grid[row][col] = -1;

        int d1 = dfs(grid, row+1, col);
        int d2 = dfs(grid, row, col+1);
        int d3 = dfs(grid, row-1, col);
        int d4 = dfs(grid, row, col-1);

        return area + d1 + d2 + d3 + d4;
    }
};
