class Solution {
public:
    void helper(int k, int n, int layer, int begin, vector<int>& path, int pathSum, vector<vector<int>>& res){
        if (pathSum == n && layer == k){
            res.push_back(path);
            return;
        }
        for (int i = begin; i <= 9; i++){
            if (layer <= k && ((pathSum + i) <= n)){
                pathSum = pathSum + i;
                path.push_back(i);
                helper(k,n,layer + 1,i + 1,path,pathSum,res);
                pathSum = pathSum - i;
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        helper(k,n,0,1,path,0,res);
        return res;
    }
};