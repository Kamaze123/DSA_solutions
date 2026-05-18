class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;    //{row, col, time}
        int row = grid.size();
        int col = grid[0].size();
        int maxtime = 0;
        int fresh = 0;

        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i,j, 0});
                }
                else if(grid[i][j] == 1){fresh++;}
            }
        }

        while(!q.empty()){
            vector<int> vec = q.front();
            q.pop();
            int x = vec[0];
            int y = vec[1];
            int t = vec[2];
            t++;

            for(vector<int> d : dir){
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx < 0 || ny < 0 || nx >= row || ny >= col){continue;}

                if(grid[nx][ny] == 0 || grid[nx][ny] == 2){continue;}

                maxtime = max(maxtime, t);

                grid[nx][ny] = 2;
                fresh--;
                q.push({nx, ny, t});
            }
        }

        if(fresh != 0){return -1;}

        return maxtime;
    }
};
