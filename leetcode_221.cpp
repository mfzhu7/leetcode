class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows == 0 || cols == 0) return 0;
        int maxSide = 0;

        vector<vector<int>>dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols;j++){
                if (matrix[i][j] == '1'){
                    if (i == 0 || j == 0){
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    }
                }
                maxSide = max(maxSide, dp[i][j]);

            }
        }
        return maxSide * maxSide;

    }
};