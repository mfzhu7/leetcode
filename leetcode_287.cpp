class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] == nums[i + 1]){
                ans = nums[i];
                break;
            }
        }
        return ans;

    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> hash;
        for (auto i : nums){
            if (hash.find(i) == hash.end()){
                hash[i] = 1;
            } else {
                ans = i;
                break;
            }
        }
        return ans;

    }
};