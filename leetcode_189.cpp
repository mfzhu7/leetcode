class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k = k % length;
        if (k == 0) return;
        vector<int> first(nums.begin(), nums.begin() + length - k);
        vector<int> second(nums.begin() + length - k, nums.end());
        for (int i = 0; i < k; i++){
            nums[i] = second[i];
        }
        for (int i = k; i < length; i++){
                nums[i] = first[i - k];
        }
        return;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size(); 
        k = k % length;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        return;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size(); 
        k = k % length;
        vector<int> array(length);
        for (int i = 0; i < length; i++){
            array[(i + k) % length] = nums[i];
        }

        nums.assign(array.begin(), array.end());
        return;
    }
};