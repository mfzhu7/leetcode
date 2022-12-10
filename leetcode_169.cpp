class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> hash;
        for (auto i: nums){
            if (hash.find(i) == hash.end()){
                hash[i] = 1;
            } else {
                hash[i] = hash[i] + 1;
            }
        }
        int res;
        for (auto it: hash){
            if (it.second > nums.size() / 2){
                res = it.first;
            }
        }
        return res;

    }
};

