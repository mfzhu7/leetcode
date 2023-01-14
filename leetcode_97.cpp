class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) return false;

        int a = m + 1;
        int b = n + 1;

        vector<vector<int>> dp(a, vector<int>(b, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= n; j++){
                int p = i + j - 1;
                if (i > 0){
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0){
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return dp[m][n];

    }
};