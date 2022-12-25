class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int ret = 1;
        int index = 0;
        while(index < nums.size() - 1){
            int length = 1;
            while(index < nums.size() - 1){
                if (nums[index] == nums[index +1]){
                    index = index + 1;
                } else if (nums[index] + 1 == nums[index + 1]){
                    index = index + 1;
                    length = length + 1;
                } else {
                    index = index + 1;
                    break;
                }
            }
            ret = ret > length ? ret : length;
        }
        return ret;

    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ret = 1;
        set<int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (hash.find(nums[i]) != hash.end()) continue;
            set<int> currHash;
            int curr = nums[i];
            currHash.insert(curr);
            while(true){
                bool flag = false;
                for(int j = 0; j < nums.size(); j++){
                    if (nums[j] == curr + 1){
                        hash.insert(nums[j]);
                        currHash.insert(nums[j]);
                        curr = nums[j];
                        flag = true;
                        break;
                    }
                }
                if (!flag) break;
            }
            if(currHash.size() > ret){
                ret = currHash.size();
            }
            currHash.clear();
        }
        return ret;
    }
};
//OOT


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        set<int> hash(nums.begin(), nums.end());

        for (auto num: hash){
            int curr = num;
            if (hash.find(curr - 1) == hash.end()){
                bool flag = false;
                while(hash.find(curr + 1) != hash.end()){
                    curr = curr + 1;
                }
            }
            ret = max(ret, curr - num + 1);
        }
        return ret;
    }
};