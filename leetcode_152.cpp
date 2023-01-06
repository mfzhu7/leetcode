class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int currMax = nums[0];
        int max_p = nums[0];
        int min_p = nums[0];

        for (int i = 1; i < nums.size(); i++){
            int temp = max_p;
            max_p = max(max(max_p * nums[i], nums[i]), min_p * nums[i]);
            min_p = min(min(temp * nums[i], nums[i]), min_p * nums[i]);
            currMax = max(currMax, max_p);
        }
        return currMax;
    }
};