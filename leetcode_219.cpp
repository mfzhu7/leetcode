class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (hash.find(nums[i]) == hash.end()){
                hash[nums[i]] = i;
            } else {
                if (abs(hash[nums[i]] - i) <= k) return true;
                else {
                    hash[nums[i]] = i;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (i > k){
                hash.erase(nums[i - k - 1]);
            }
            if (hash.count(nums[i])) return true;
            hash.emplace(nums[i]);
        }
        return false;
    }
};