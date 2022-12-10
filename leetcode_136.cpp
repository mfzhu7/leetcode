class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> hash;
        for (auto i: nums){
            if (hash.find(i) == hash.end()){
                hash[i] = 1;
            } else {
                hash[i]++;
            }
        }
        int res = 0;
        for(auto it: hash){
            if (it.second == 1) res = it.first;
        }
        return res;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto i: nums){
            res = res ^ i;
        }
        return res;
    }
};