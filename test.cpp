#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>


using namespace std;

void print(vector<int> nums){
    for (auto i: nums){
        cout << i << " ";
    }
    cout << endl;
    return;
}


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 1; i < grid.size(); i++){
            grid[i][0] = grid[i][0] + grid[i - 1][0];
        }
        for(int j = 1; j < grid[0].size(); j++){
            grid[0][j] = grid[0][j - 1] + grid[0][j - 1];
        }
        for (int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                grid[i][j] = min(grid[i-1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;
        return grid[row][col];

    }
};


int main(){
    vector<vector<int>> matrix {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    Solution test;
    test.minPathSum(matrix);
}