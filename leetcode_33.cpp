class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ret = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                ret = i;
                break;
            }
        }
        return ret;
    }
};
//暴力解法


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ret = -1;
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[0]){
                if (target >= nums[0] && target < nums[mid]){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[nums.size() - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return ret;
    }
};

//二分+递归的思想