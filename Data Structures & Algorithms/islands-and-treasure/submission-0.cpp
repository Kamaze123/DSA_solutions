class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){

                if(grid[i][j] == 0){
                    grid[i][j] = -2;
                   bfs(grid, 0,i,j);
                   grid[i][j] = 0;
                }

            }
        }
    }

    void bfs(vector<vector<int>>& grid , int level, int row, int col){
        if(row < 0 || col < 0 ||  row >= grid.size() || col >= grid[0].size()){
            return;
        }

        if(grid[row][col] == -1 || grid[row][col] == 0){
            return;
        }

        if(level >= grid[row][col] && grid[row][col] != -2){
            return;
        }

        if(level < grid[row][col] && grid[row][col] != -2){
            grid[row][col] = level;
        }

        bfs(grid, level+1, row+1, col);
        bfs(grid, level+1, row, col+1);
        bfs(grid, level+1, row-1, col);
        bfs(grid, level+1, row, col-1);

    }
};
