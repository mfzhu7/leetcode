class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (auto i :nums){
            xorsum ^= i;
        }

        xorsum = (xorsum == INT_MIN) ? xorsum : xorsum & (-1 * xorsum);
        int type1 = 0;
        int type2 = 0;
        for (auto i : nums){
            if (xorsum & i){
                type1 ^= i;
            } else {
                type2 ^= i; 
            }
        }
        return {type1,type2};

    }
};


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;
        for (auto it: nums){
            hash[it] += 1;
        }
        vector<int> ret;
        for (auto it: hash){
            if (it.second == 1){
                ret.push_back(it.first);
            }
        }
        return ret;

    }
};