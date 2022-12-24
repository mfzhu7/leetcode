class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret{-1, -1};
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target){
                int left = mid;
                int right = mid;
                while(left > 0 && nums[left] == nums[left - 1]){
                    left = left - 1;
                }
                while(right < nums.size() - 1 && nums[right] == nums[right + 1]){
                    right = right + 1;
                }
                ret[0] = left;
                ret[1] = right;
                return ret;
            } else {
                if (nums[mid] > target) r = r - 1;
                else l = l + 1;
            }
        }
        return ret;
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret{-1, -1};
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target){
                ret[0] = mid;
                r = mid - 1;}
            else {
                if (nums[mid] > target) r = mid - 1;
                if (nums[mid] < target) l = mid  + 1;
            }
        }
        l = 0;
        r = nums.size() - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] == target){
                ret[1] = mid;
                l = mid + 1;
            }
            else {
                if (nums[mid] > target) r = mid - 1;
                if (nums[mid] < target) l = mid  + 1;
            }
        }

        return ret;
    }
};