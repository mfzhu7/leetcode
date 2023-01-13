class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto i: nums){
            hash[i] = hash[i] +1;
        }
        int res = 0;
        for (auto it: hash){
            if (it.second == 1){
                res = it.first;
                break;
            }
        }
        return res;

    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++){
            int total = 0;
            for (int num: nums){
                total += ((num >> i) & 1);
            }
            if (total % 3){
                ans |= (1 << i);
            }
        }
        return ans;

    }
};