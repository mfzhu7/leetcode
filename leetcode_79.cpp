class Solution {
public:
    void helper(vector<int>& nums, int begin, vector<int> path, vector<vector<int>>& ret){
        if (path.size() <= nums.size()) ret.push_back(path);
        
        set<int> layer;
        for (int i = begin; i < nums.size(); i++){
            if (layer.find(nums[i]) == layer.end()){
                layer.insert(nums[i]);
                path.push_back(nums[i]);
                helper(nums, i + 1, path, ret);
                path.pop_back();
            }

        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> ret;
        helper(nums, 0, path, ret);
        return ret;
    }
};