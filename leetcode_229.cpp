class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++){
            hash[nums[i]] += 1;
        }
        for (auto it: hash){
            if (it.second > (n / 3)){ret.push_back(it.first);}
        }
        return ret;


    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1 = 0;
        int element2 = 0;
        int vote1 = 0;
        int vote2 = 0;
        for (auto num: nums){
            if (vote1 > 0 && element1 == num){
                vote1++;
            } else if (vote2 > 0 && element2 == num){
                vote2++;
            } else if (vote1 == 0){
                vote1++;
                element1 = num;
            } else if (vote2 == 0){
                vote2++;
                element2 = num;
            } else {
                vote1--;
                vote2--;
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for (auto num: nums){
            if (vote1 > 0 && num == element1) cnt1++;
            if (vote2 > 0 && num == element2) cnt2++;
        }
        vector<int> ret;
        if (vote1 > 0 && cnt1 > nums.size() / 3) ret.push_back(element1);
        if (vote2 > 0 && cnt2 > nums.size() / 3) ret.push_back(element2);
        return ret;
    }
};