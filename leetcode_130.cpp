class Solution {
public:
    bool helper(vector<vector<char>>& board, int row, int col, vector<vector<int>>& visit, vector<vector<int>>& path){
        if (row == 0 || col == 0 || row == board.size() - 1 || col == board[0].size() - 1){
            bool ret = (board[row][col] == 'X') ? true : false;
            return ret;
        }

        if (board[row][col] == 'X') return true;
        if (visit[row][col]) return true;

        visit[row][col] = 1;
        vector<int> temp = {row, col};
        path.push_back(temp);

        return helper(board,row - 1,col,visit,path) && helper(board,row + 1,col,visit,path) \
          && helper(board,row,col - 1,visit,path) && helper(board,row,col + 1,visit,path);
    }
    void change(vector<vector<char>>& board, vector<vector<int>> path){
        for (int i = 0; i < path.size(); i++){
            board[path[i][0]][path[i][1]] = 'X';
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size() - 1;
        int col = board[0].size() - 1;
        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                if (board[i][j] == 'X') continue;
                vector<vector<int>> visit(row + 1, vector<int>(col + 1,0));
                vector<vector<int>> path;
                bool ret = helper(board,i,j,visit,path);
                if (ret){
                    change(board,path);
                }
            }
        }
        return;
    }
};


class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y){
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 'O'){
            return;
        }
        board[x][y] = 'A';
        dfs(board,x - 1, y);
        dfs(board,x + 1, y);
        dfs(board,x, y + 1);
        dfs(board,x, y - 1);
        return;

    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < col; i = i + 1){
                dfs(board,0,i);
                dfs(board,row - 1, i);
        }
        for (int i = 1; i < row - 1; i = i + 1){
            dfs(board,i, 0);
            dfs(board,i, col - 1);
        }
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col;j++){
                if (board[i][j] == 'A'){
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                 }
            }
        }
        return;

    }
};