class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4) return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++){
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int l = j + 1;
                int r = nums.size() - 1;
                while(l < r){
                     long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target){
                        ret.push_back({nums[i],nums[j],nums[l], nums[r]});
                        while(l < r && nums[l] == nums[l + 1]) l++;
                        while(l < r && nums[r] == nums[r - 1]) r--;
                        l = l + 1;
                        r = r - 1;
                    } else if (sum > target){
                        r = r - 1;
                    } else {
                        l = l + 1;
                    }
                }
            }
        }
        return ret;

    }
};