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