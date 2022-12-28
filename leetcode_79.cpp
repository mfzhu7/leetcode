class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int x, int y, int index, vector<vector<int>>& record){
        if (x < 0 or y < 0 or x >= board.size() or y >= board[0].size() or record[x][y] == 1) return false;
        if (word[index] != board[x][y]) return false;
        if (word[index] == board[x][y] && index == word.size() - 1) return true;

        record[x][y] = 1;
        bool up = helper(board,word,x - 1,y,index + 1,record);
        bool down = helper(board,word,x + 1,y,index + 1,record);
        bool left = helper(board,word,x,y - 1,index + 1,record);
        bool right = helper(board,word,x,y + 1,index + 1,record);
        record[x][y] = 0;

        return up||down||left||right;

    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> row(board[0].size(), 0);
        vector<vector<int>> record(board.size(), row);

        for(int i = 0; i < board.size(); i++){
            for (int j = 0;j < board[0].size();j++){
                bool res = helper(board,word,i,j,0,record);
                if(res) return res;
            }
        }
        return false;

    }
};