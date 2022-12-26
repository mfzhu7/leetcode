class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int ret = nums[0]; 
        for (int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};