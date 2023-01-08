class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != i) return i;
        } 
        return nums.size();

    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1, -1);
        for (int i = 0; i < nums.size(); i++){
            hash[nums[i]] = 1;
        }
        for (int i = 0; i <= nums.size(); i++){
            if (hash[i] == -1) return i;
        }
        return 0;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int end = nums.size();
        int total = (end) * (end + 1) / 2;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            ans += nums[i];
        }
        return total - ans;

    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++){
            ans ^= nums[i];
        }
        for (int i = 0; i <= nums.size(); i++){
            ans ^= i;
        }
        return ans;

    }
};