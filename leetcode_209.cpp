class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int length = nums.size();
        int currSum = 0;
        int minLength = INT_MAX;
        while(end < length){
            currSum += nums[end];
            if(currSum >= target){
                while(currSum >= target){
                minLength = min(minLength, end - start + 1);
                currSum = currSum - nums[start];
                start++;
                }
                end++;
            }else {
                end = end + 1;
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};