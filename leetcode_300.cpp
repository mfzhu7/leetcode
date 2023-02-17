class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++){
            int temp = 1;
            for (int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    temp = max(temp, dp[j] + 1);
                }
            }
            dp[i] = temp;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};




