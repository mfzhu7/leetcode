#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

using namespace std;


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

        return helper(board,row - 1,col,visit,path) && helper(board,row + 1,col,visit,path) && helper(board,row,col - 1,visit,path) && helper(board,row,col + 1,visit,path);
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
        for (int i = 1; i < row - 1; i++){
            for (int j = 1; j < col - 1; j++){
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

int main(){
    vector<vector<char>> board = {{'X','X','X'},{'X','O','X'},{'X','X','X'}};
    Solution test;
    test.solve(board);
}
