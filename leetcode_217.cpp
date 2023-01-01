class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (hash.find(nums[i]) == hash.end()){
                hash[nums[i]] == 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return false;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;

    }
};