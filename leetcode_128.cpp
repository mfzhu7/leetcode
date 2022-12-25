class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int ret = 1;
        int index = 0;
        while(index < nums.size() - 1){
            int length = 1;
            while(index < nums.size() - 1){
                if (nums[index] == nums[index +1]){
                    index = index + 1;
                } else if (nums[index] + 1 == nums[index + 1]){
                    index = index + 1;
                    length = length + 1;
                } else {
                    index = index + 1;
                    break;
                }
            }
            ret = ret > length ? ret : length;
        }
        return ret;

    }
};