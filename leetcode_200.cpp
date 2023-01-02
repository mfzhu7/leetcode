class Solution {
public:
    bool dfs(vector<vector<char>>& grid, int row, int col){
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0' || grid[row][col] == 'A') return true;

        grid[row][col] = 'A';

        return dfs(grid,row - 1,col) && dfs(grid,row + 1,col) && dfs(grid,row,col - 1) && dfs(grid,row,col + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 'A' || grid[i][j] == '0') continue;
                bool temp = dfs(grid, i, j);
                if (temp) ret = ret + 1;
                
            }
        }
        return ret;
    }
};