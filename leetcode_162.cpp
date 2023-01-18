class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++){
            int left = (i - 1 >= 0) ? nums[i - 1] : INT_MIN;
            int right= (i + 1 < nums.size()) ? nums[i + 1]: INT_MIN;
            if (nums[i] > left && nums[i] > right) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};