class Solution {
public:
    bool help(vector<vector<char>>& board, int pos1, int pos2){
        vector<int> hash(10,0);
        for (int i = pos1; i <= pos1 + 2; i++){
            for (int j = pos2; j <= pos2 + 2; j++){
                if (board[i][j] == '.') continue;
                int index = board[i][j] - '0';
                if (hash[index] == 1) return false;
                else {hash[index] = 1;}
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        
        for (int i = 0; i < 9; i++){
            vector<int> hash(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int index = board[i][j] - '0';
                if (hash[index] == 1) return false;
                else hash[index] = 1;
            }
        }
        for (int i = 0; i < 9; i++){
            vector<int> hash(10, 0);
            for(int j = 0; j < 9; j++){
                if (board[j][i] == '.') continue;
                int index = board[j][i] - '0';
                if (hash[index] == 1) return false;
                else hash[index] = 1;
            }
        }

        for (int i = 0; i < 9; i = i + 3){
            for (int j = 0; j < 9; j = j +3){
                bool tmp = help(board, i, j);
                if (!tmp) return tmp;
            }
        }
        return true;

    }
};