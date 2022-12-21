class Solution {
public:
    void helper(vector<int>& nums, int begin, vector<int> path, vector<vector<int>>& ret){
        if(path.size() <= nums.size()) ret.push_back(path);
            
        for(int i = begin; i < nums.size(); i++){
            path.push_back(nums[i]);
            helper(nums, i + 1, path, ret);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ret;
        helper(nums, 0, path,ret);
        return ret;

    }
};