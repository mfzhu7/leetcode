class Solution {
public:
    void helper(vector<int>& nums, int target, int& count, int pathSum){
        if (pathSum == target){
            count = count + 1;
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (pathSum + nums[i] <= target){
                pathSum = pathSum + nums[i];
                helper(nums,target,count,pathSum);
                pathSum = pathSum - nums[i];
            }
        }
        return ;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int pathSum = 0;
        int count = 0;
        helper(nums,target,count,pathSum);
        return count;

    }
};




class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int j = 1; j <= target; j++){
        for (auto num: nums){
            if (j - num >= 0){
                dp[j] = dp[j] + dp[j - num];
            }
        }
        }
        return *(dp.end() - 1);
 
    }
};