class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return 1;
        int slow = 0;
        int fast = 0; 
        while(fast < nums.size()){
            if (nums[slow] != nums[fast]){
                nums[slow + 1] = nums[fast];
                slow = slow + 1;
            }
            fast = fast + 1;
        }
        return slow + 1;

    }
};