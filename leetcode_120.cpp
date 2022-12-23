class Solution {
public:
    void helper(vector<vector<int>>& triangle, int& ret, int pathSum, int row, int col){
        if(row >= triangle.size()){
            ret = pathSum < ret ? pathSum : ret;
            return;
        }
        helper(triangle, ret, pathSum + triangle[row][col], row + 1, col);
        helper(triangle, ret, pathSum + triangle[row][col], row + 1, col + 1);
        return;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int ret = INT_MAX;
        helper(triangle,ret,0,0,0);
        return ret;
    }
};// OOT



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int num = triangle.size();
        vector<int> row(num, 0);
        vector<vector<int>> dp(num, row);
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < num; i++){
            for (int j = 0; j <= i; j++){
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                }
                else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                }
                else {
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }
        int ret = INT_MAX;
        for (auto i: dp[num-1]){
            ret = min(ret, i);
        }
        return ret;
    }
};

// DP规划