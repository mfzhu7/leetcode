class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size();i++){
            if (prices[i] > prices[i - 1]){
                ans = ans + prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        vector<vector<int>> dp(length, vector<int>(2,0));

        dp[0][0] = 0;
        dp[0][1] = -1 * prices[0];

        for (int i = 1; i < length; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }   

        return dp[length - 1][0];
    }
};