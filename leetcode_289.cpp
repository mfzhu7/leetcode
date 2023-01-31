class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<int> row(c, 0);
        vector<vector<int>> hash(r, row);

        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                vector<int> x = {i - 1,i - 1,i - 1,i,i,i + 1,i + 1,i + 1};
                vector<int> y = {j - 1,j,j + 1,j - 1,j + 1,j - 1,j,j + 1};
                int total = 0;
                for (int i = 0; i < 8; i++){
                    if (x[i] < 0 or x[i] >= r or y[i] < 0 or y[i] >= c){
                        continue;
                    } else {
                        total += board[x[i]][y[i]];
                    }
                }
                hash[i][j] = total;
            }
        }
        for(int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if(board[i][j] == 1){
                    if (hash[i][j] > 3 || hash[i][j] < 2){
                        board[i][j] = 0;
                    }

                }else{
                    if (hash[i][j] == 3){
                        board[i][j] = 1;
                    }
                }
            }
        }

    }
};


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[3] = {-1, 0, 1};
        int rows = board.size();
        int cols = board[0].size();

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                int livenei = 0;
                for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                        if (!(neighbors[i] == 0 && neighbors[j] == 0)){
                            int r = row + neighbors[i];
                            int c = col + neighbors[j];

                            if (r >= 0 && c >= 0 && r < rows && c < cols && abs(board[r][c]) == 1){
                                livenei += 1;
                            }
                        }
                    }
                }

                if (board[row][col] == 1 && (livenei < 2 || livenei > 3)){
                    board[row][col] = -1;
                }
                if (board[row][col] == 0 && livenei == 3){
                    board[row][col] = 2;
                }
            }
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (board[i][j] > 0){
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
        return;

    }
};