class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n = nums.size();
        int idx = 0;
        while(idx < n){
            if ((idx == n - 1) || (idx + 1 < n && nums[idx] + 1 != nums[idx + 1])){
                ret.push_back(to_string(nums[idx]));
                idx = idx + 1;
            } else {
                int start = idx;
                while(idx + 1 < n && nums[idx] + 1 == nums[idx + 1]){
                    idx = idx + 1;
                }
                ret.push_back(to_string(nums[start]) + "->" + to_string(nums[idx]));
                idx = idx + 1;
            }
        }
        return ret;

    }
};