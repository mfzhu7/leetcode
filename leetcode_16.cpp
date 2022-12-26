class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = 1e7;

        for (int i = 0; i < nums.size() - 2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(ret - target)) ret = sum;
                if (sum == target) return sum;
                if (sum > target){
                    r = r - 1;
                } else { 
                    l = l + 1;
                }
            }
        }
        return ret;

    }
};