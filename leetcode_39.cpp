class Solution {
public:
    void helper(vector<int>&candidates, int target, int begin, vector<vector<int>>& res, vector<int>& path, int pathSum){
        if (pathSum == target){
            res.push_back(path);
            return;
        }
        for (int i = begin; i < candidates.size(); i++){
            if (pathSum + candidates[i] <= target){
                pathSum = pathSum + candidates[i];
                path.push_back(candidates[i]);
                helper(candidates,target,i,res,path,pathSum);
                path.pop_back();
                pathSum = pathSum - candidates[i];
            }
        }
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        int pathSum = 0;
        int begin = 0;
        helper(candidates,target,begin,res,path,pathSum);
        return res;
        
    }
};