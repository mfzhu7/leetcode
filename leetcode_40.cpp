class Solution {
public:
    void helper(vector<int>& candidates, int target, int begin, vector<int>& path, vector<vector<int>>& res, int pathSum){
        if (pathSum == target){
            res.push_back(path);
            return;
        }
        set<int> layNum;
        for (int i = begin; i < candidates.size(); i++){
            if ((pathSum + candidates[i] <= target) && layNum.find(candidates[i]) == layNum.end()){
                layNum.insert(candidates[i]);
                pathSum = pathSum + candidates[i];
                path.push_back(candidates[i]);
                helper(candidates,target, i + 1,path,res,pathSum);
                pathSum = pathSum - candidates[i];
                path.pop_back();
            }
        }
        return;
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        int pathSum = 0;
        helper(candidates,target,0,path,res,pathSum);
        return res;

    }
};