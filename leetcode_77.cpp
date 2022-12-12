class Solution {
public:
    void helper(int n, int k, int begin, vector<vector<int>>& res, vector<int>& path){
        if (path.size() == k){
            res.push_back(path);
            return;
        }
        for (int i = begin; i <= n; i++){
            if (path.size() <= k){
                path.push_back(i);
                helper(n, k, i + 1, res, path);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        helper(n,k,1,res,path);
        return res;

    }
};