class Solution {
public:
    int helper(vector<int>& nums, int start, int end){
        if (start > end) return 0;
        if (start == end) return nums[start];
        if (end - start == 1) return max(nums[start], nums[end]);
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        int index = 2;
        for (int i = start + 2;i <= end; i++){
            dp[index] = max(dp[index - 2] + nums[i], dp[index - 1]);
            index = index + 1;
        }
        return dp[dp.size() - 1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int max_1 = helper(nums, 0, nums.size() - 2);
        int max_2 = helper(nums,1, nums.size() - 3) + nums[nums.size() - 1];
        return max(max_1, max_2);

    }
};


class Solution {
public:
    int helper(vector<int>& nums, int start, int end){
        int first = nums[start];
        int second = max(nums[start], nums[start + 1]);

        for (int i = start + 2;i <= end; i++){
            int  temp = max(first + nums[i], second);
            first = second;
            second = temp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        return max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() -1));

    }
};