class Solution {
public:
    int findMin(vector<int>& nums) {
        int ret = INT_MAX;
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[0]){
                ret = min(ret, nums[0]);
                l = mid + 1;
            } else {
                ret = min(ret, nums[mid]);
                r = mid - 1;
            }
        }
        return ret;
    }
};
//二分查找
