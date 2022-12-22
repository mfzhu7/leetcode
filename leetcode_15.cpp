class Solution {
public:
    void helper(vector<int>& nums, int begin, vector<vector<int>>& res, vector<int>& path, int pathSum){
        if (pathSum == 0 && path.size() == 3){
            res.push_back(path);
            return;
        }
        set<int> layer;
        for (int i = begin; i < nums.size(); i++){
            if (pathSum + nums[i] <= 0 && path.size() < 3 && layer.find(nums[i]) == layer.end()){
                layer.insert(nums[i]);
                path.push_back(nums[i]);
                helper(nums,i + 1, res,path, pathSum + nums[i]);
                path.pop_back();
            }
        }
        return;

    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        helper(nums,0,res,path,0);
        return res;

    }
};
//OOT


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        while(index < nums.size() - 2){
            if (nums[index] > 0) return ret;
            if (index > 0 && nums[index] == nums[index - 1]) {
                index = index + 1;
                continue;
            };

            int L = index + 1;
            int R = nums.size() - 1;

            while(L < R){
                if (nums[L] + nums[R] + nums[index] == 0){
                    ret.push_back({nums[L],nums[R],nums[index]});
                    while(L < R && nums[L] == nums[L + 1]) L = L + 1;
                    while(L < R && nums[R] == nums[R - 1]) R = R - 1;
                    L = L + 1;
                    R = R - 1;
                } else if (nums[L] + nums[R] + nums[index] > 0){
                    R = R - 1;
                } else {
                    L = L + 1;
                }
            }
            index = index + 1;
        }
        return ret;

    }
}; 
//双指针+排序
