class Solution {
public:
    void helper(vector<int>& coins, int left, vector<int>& path, int& minn){
        if(left < 0 || path.size() > minn) return;
        if(left == 0){
            minn = min(minn, (int)path.size());
            return;
        }
        for (int i = 0; i < coins.size(); i++){
            path.push_back(coins[i]);
            helper(coins, left - coins[i], path, minn);
            path.pop_back();
        }
        return;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> path;
        int minn = INT_MAX;
        helper(coins, amount, path, minn);
        if (minn == INT_MAX) return -1;
        return minn;
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            // sort(coins.begin(), coins.end());
            int MAX = amount + 1;
            vector<int> dp(amount + 1, MAX);
            dp[0] = 0;
            for (int i = 1;i <= amount; i++){
                for (int j = 0; j < (int)coins.size(); j++){
                    if(i >= coins[j]){
                        dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                    }
                }
            }

            return dp[amount] > amount? -1: dp[amount]; 

    }
};